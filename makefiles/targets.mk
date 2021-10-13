################################################################################
# TARGETS
#
# [R]: Single value variable can be redefined in other makefiles
# [+]: Values can be added to the variable in other makefiles
# [X]: Variable must not be redefined nor values be added to it
################################################################################
ifneq ($(PROJECT_TYPE),$(findstring $(PROJECT_TYPE),header program shared static))
    $(error PROJECT_TYPE must be one of [header, program, shared, static])
endif

ifneq ($(BUILD_MODE),$(findstring $(BUILD_MODE),debug release))
    $(error BUILD_MODE must be one of [debug, release])
endif

ifneq ($(COVERAGE),$(findstring $(COVERAGE),true false))
    $(error COVERAGE must be one of [true, false])
endif

# Build project and tests(if there is a test folder) with the default build mode
# (debug).
.PHONY: all
all:: $(PROJECT_DEPS) $(PROJECT_TYPE) $(TEST_TARGET)

# Same as `all` target but also build in release mode.
.PHONY: all_dr
all_dr::
	$(MAKE) all BUILD_MODE=debug
	$(MAKE) all BUILD_MODE=release

# Compile *.c files
$(OBJ_PATH)/%.o: %.c $(OBJ_DEPS)
	$(COMPILE)
################################################################################
# HEADER PROJECT
################################################################################
ifeq ($(PROJECT_TYPE),header)
# Nothing to build for header only project(tests are built with the `test`
# target).
SRC_DIRS :=
COV_CMD :=
.PHONY: header
header::;
endif
################################################################################
# HEADER/LIBRARY PROJECT COMMON
################################################################################
ifeq ($(PROJECT_TYPE),$(findstring $(PROJECT_TYPE),header shared static))
# Install header files(*.h)
INSTALL_DEPS := install_header
.PHONY: install_header
install_header:: $(PKG_HEADER_TARGET) | $(HEADER_INSTALL_PATH) $(PKG_PC_INSTALL_PATH)
	cp -r $(INC_PATH)/. $(HEADER_INSTALL_PATH)
	mv $(PKG_PC_NAME) $(PKG_PC_INSTALL_PATH)

# *.pc.in => *.pc
$(PKG_HEADER_TARGET)::
	$(PKG_PC_IN)

# Uninstall header files(*.h/*.pc)
UNINSTALL_DEPS := uninstall_header
.PHONY: uninstall_header
uninstall_header::
	rm -r $(HEADER_INSTALL_PATH)
	rm $(PKG_PC_INSTALL_PATH)/$(PKG_PC_NAME)
endif
################################################################################
# LIBRARY PROJECT
################################################################################
ifeq ($(PROJECT_TYPE),$(findstring $(PROJECT_TYPE),shared static))
# Install library files(*.a/*.so)
INSTALL_DEPS := install_lib
.PHONY: install_lib
install_lib:: install_header | $(LIB_INSTALL_PATH)
	cp -ar $(BUILD_PATH)/* $(LIB_INSTALL_PATH)
	find $(EXT_LIB_PATH) -type f,l -exec cp -at $(LIB_INSTALL_PATH) {} +

# Build shared library(*.so)
.PHONY: shared
shared:: $(LIB_SHARED_TARGET)

# *.o => *.so.*
$(LIB_SHARED_TARGET): $(OBJ_FILES) | $(BUILD_PATH)
	$(LINK_SHARED)
	ln -sf $(LIB_SHARED_XYZ) $(LIB_SHARED_X_PATH)
	ln -sf $(LIB_SHARED_X) $(LIB_SHARED_PATH)

# Build static library(*.a)
.PHONY: static
static:: $(LIB_STATIC_TARGET)

# *.o => *.a
$(LIB_STATIC_TARGET): $(OBJ_FILES) | $(BUILD_PATH)
	$(ARCHIVE)

# Uninstall library files(*.a/*.so.*/*.h/*.pc)
UNINSTALL_DEPS := uninstall_lib
.PHONY: uninstall_lib
uninstall_lib:: uninstall_header
	rm -r $(LIB_INSTALL_PATH)
endif
################################################################################
# PROGRAM PROJECT
################################################################################
# Build program
ifeq ($(PROJECT_TYPE),program)
.PHONY: program
program:: $(PROGRAM_TARGET)

# *.o => executable
$(PROGRAM_TARGET): $(OBJ_FILES) | $(BUILD_PATH)
	$(LINK_PROGRAM)

# Run program
RUN_CMD = $(PROGRAM_PATH)
.PHONY: run
run:: $(RUN_DEPS)
	$(RUN_CMD)
endif
################################################################################
# TEST
################################################################################
# Build tests if there is a test folder
ifneq ($(TEST_TARGET),empty_target)
.PHONY: $(TEST_TARGET)
$(TEST_TARGET):: test
.PHONY: test
test::
	$(MAKE) -C $(TEST_PATH) all CC=$(CC) BUILD_MODE=$(BUILD_MODE) \
	MAKEFILE_PATH=../$(MAKEFILE_PATH)

PRE_PASS_DEPS = pre_pass_test
.PHONY: pre_pass_test
pre_pass_test::
	$(MAKE) -C $(TEST_PATH) pre_pass MAKEFILE_PATH=../$(MAKEFILE_PATH)

# Run tests(they must be build first)
.PHONY: check
check::
	$(MAKE) -C $(TEST_PATH) run BUILD_MODE=$(BUILD_MODE) \
	MAKEFILE_PATH=../$(MAKEFILE_PATH)

# Remove test build files
CLEAN_DEPS := clean_test
.PHONY: clean_test
clean_test::
	$(MAKE) -C $(TEST_PATH) clean MAKEFILE_PATH=../$(MAKEFILE_PATH)

# Tests coverage
COV_DEPS := cov_test
.PHONY: cov_test
cov_test::
	$(MAKE) -C $(TEST_PATH) cov MAKEFILE_PATH=../$(MAKEFILE_PATH)
endif
################################################################################
# CODE ANALYSIS/COVERAGE - DOC
################################################################################
# Analyze code with various tools
.PHONY: analyze
analyze:: | $(SCANBUILD_PATH) $(CPPCHECK_PATH)
	$(SCANBUILD)
	$(CPPCHECK)

# Code coverage tools
.PHONY: cov
cov:: $(COV_DEPS) | $(LCOV_PATH)
	$(COV_CMD)

# Generate documentation
.PHONY: doc
doc:: | $(DOXYGEN_PATH)
	$(DOXYGEN)
################################################################################
# CLEAN/REBUILD/INSTALL/UNINSTALL/PREPROCESSOR
################################################################################
# Remove build files
CLEAN_CMD = rm -rf $(BUILD_ROOT_PATH)
.PHONY: clean
clean:: $(CLEAN_DEPS)
	$(CLEAN_CMD)

# Remove existing build files and build again
.PHONY: rebuild
rebuild:: clean all

# Install everything
.PHONY: install
install:: $(INSTALL_DEPS)

# Uninstall everything
.PHONY: uninstall
uninstall:: $(UNINSTALL_DEPS)

# Only output the result of the preprocessor pass.
.PHONY: pre_pass
pre_pass:: $(PRE_FILES) $(PRE_PASS_DEPS)

# Implicit rule to output the result of the preprocessor pass.
$(PRE_PATH)/%.pre: %.c $(PRE_DEPS)
	$(PREPROCESSOR)
################################################################################
# MISC
################################################################################
# Targets depending on the existence of an optional file/directory are
# redirected here to avoid make failing with `No rule to make target`.
.PHONY: empty_target
empty_target::;
%::;
# Targets to create output directories when they are needed but don't exist yet.
# mkdir -p: No error if directory exists and make parent directories as needed
$(ANALYSIS_PATH):       ;mkdir -p $(ANALYSIS_PATH)
$(BUILD_PATH):          ;mkdir -p $(BUILD_PATH)
$(CPPCHECK_PATH):       ;mkdir -p $(CPPCHECK_PATH)
$(DEP_PATH):            ;mkdir -p $(DEP_PATH)
$(DOXYGEN_PATH):        ;mkdir -p $(DOXYGEN_PATH)
$(HEADER_INSTALL_PATH): ;mkdir -p $(HEADER_INSTALL_PATH)
$(LCOV_PATH):           ;mkdir -p $(LCOV_PATH)
$(LIB_INSTALL_PATH):    ;mkdir -p $(LIB_INSTALL_PATH)
$(OBJ_PATH):            ;mkdir -p $(OBJ_PATH)
$(PKG_PC_INSTALL_PATH): ;mkdir -p $(PKG_PC_INSTALL_PATH)
$(PRE_PATH):            ;mkdir -p $(PRE_PATH)
$(SCANBUILD_PATH):      ;mkdir -p $(SCANBUILD_PATH)
$(VALGRIND_PATH):       ;mkdir -p $(VALGRIND_PATH)
# Make each *.d file a target so make won't fail if the file doesn't exist
$(DEP_FILES):
# Only include *.d files if needed
ifeq ($(MAKECMDGOALS),$(findstring $(PROJECT_TYPE),program shared static))
    include $(wildcard $(DEP_FILES))
endif
# Delete files generated by a target which failed(prevent corrupted files)
.DELETE_ON_ERROR:
