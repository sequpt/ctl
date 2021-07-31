################################################################################
# PROJECT
#
# [R]: Single value variable can be redefined in other makefiles
# [+]: Values can be added to the variable in other makefiles
# [X]: Variable must not be redefined nor values be added to it
################################################################################
# Project name: must not contain spaces                                      [R]
PROJECT := untitled
# Project type: one of [header, program, shared, static]                     [R]
PROJECT_TYPE := program
# Incompatible API changes                                                   [R]
VERSION_MAJOR := 0
# Functionality in a backwards compatible manner added                       [R]
VERSION_MINOR := 1
# Backwards compatible bug fixes                                             [R]
VERSION_PATCH := 0
# Full version(default to 0.1.0)                                             [X]
VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)
################################################################################
# BUILD
################################################################################
# Build mode(default to debug)                                               [R]
# Change build mode at runtime with 'make <target> BUILD_MODE=release'
BUILD_MODE ?= debug
# Output folder for executables, *.a, *.so, etc                              [X]
BUILD_FOLDER := build
# Output folder for generated dependency files(*.d)                          [X]
DEP_FOLDER := dep
# Input folder for header files(*.h)                                         [X]
INC_FOLDER := include
# Output folder for object files(*.o)                                        [X]
OBJ_FOLDER := obj
# Input folder for source files(*.c)                                         [X]
SRC_FOLDER := src
# Input folder for tests                                                     [X]
TEST_FOLDER := test
# Paths to above folders                                                     [R]
BUILD_ROOT_PATH = $(BUILD_FOLDER)
BUILD_PATH      = $(BUILD_ROOT_PATH)/$(BUILD_MODE)
DEP_PATH        = $(BUILD_PATH)/$(DEP_FOLDER)
INC_PATH        = $(INC_FOLDER)
OBJ_PATH        = $(BUILD_PATH)/$(OBJ_FOLDER)
SRC_PATH        = $(SRC_FOLDER)
TEST_PATH       = $(TEST_FOLDER)
# Target to build tests                                                      [X]
# Expand to $(TEST_PATH)empty_target if $(TEST_PATH) points to an existing
# folder or to `empty_target` otherwise.
TEST_TARGET = $(wildcard $(TEST_PATH))empty_target
# List of directories containing header files(*.h)                           [+]
INC_DIRS = $(INC_PATH)
# List of directories containing source files(*.c)                           [+]
SRC_DIRS = $(shell find $(SRC_PATH)/ -type d)
# Paths in which to look for source files in rules like %.o: %.c             [X]
# Modify SRC_DIRS if other directories must be added to VPATH
VPATH = $(SRC_DIRS)
# List of source files(*.c)                                                  [+]
SRC_FILES = $(sort $(shell find $(SRC_DIRS) -name '*.c' -type f))
# Change .c extension to .o and remove directory-part(path/to/foo.c => foo.o)[X]
OBJ_FILES_PASS1 = $(notdir $(SRC_FILES:.c=.o))
# Prefix all files with $(OBJ_PATH)(foo.o => ./obj/debug/foo.o)              [+]
OBJ_FILES = $(OBJ_FILES_PASS1:%=$(OBJ_PATH)/%)
# Change .o extension to .d(foo.o => foo.d)                                  [X]
DEP_FILES_PASS1 = $(OBJ_FILES_PASS1:.o=.d)
# Prefix all files all with $(DEP_PATH)(foo.d => ./dep/foo.d)                [X]
DEP_FILES = $(DEP_FILES_PASS1:%=$(DEP_PATH)/%)
# Dependencies for %.o: %.c rule                                             [X]
OBJ_DEPS = $(DEP_PATH)/%.d | $(OBJ_PATH) $(DEP_PATH)
################################################################################
# EXTERNAL
################################################################################
# Input folder for third-parties sources, libraries, tools, etc              [X]
EXTERNAL_FOLDER := external
# Input folder for third-parties headers                                     [X]
EXTERNAL_INC_FOLDER := include
# Input folder for third-parties libraries                                   [X]
EXTERNAL_LIB_FOLDER := lib
# Paths to above folders                                                     [R]
EXTERNAL_PATH = $(EXTERNAL_FOLDER)
EXTERNAL_INC_PATH = $(EXTERNAL_PATH)/$(EXTERNAL_INC_FOLDER)
EXTERNAL_LIB_PATH = $(EXTERNAL_PATH)/$(EXTERNAL_LIB_FOLDER)
# List of directories containing third-parties libraries                     [+]
EXTERNAL_LIB_DIRS = $(shell find $(EXTERNAL_LIB_PATH)/ -type d)
# Output folder for third-parties                                            [X]
EXTERNAL_INSTALL_PREFIX := $(CURDIR)/$(EXTERNAL_PATH)
# Command to invoke submakes in external folder                              [X]
EXTERNAL_SUBMAKE = $(MAKE) -C $(EXTERNAL_PATH)
# List of directories containing *.h files                                   [+]
INC_DIRS += $(wildcard $(EXTERNAL_PATH))
INC_DIRS += $(wildcard $(EXTERNAL_INC_PATH))
################################################################################
# PROGRAM
################################################################################
# Name of the program to build                                               [R]
PROGRAM_NAME = $(PROJECT)
# Output folder for the project program                                      [X]
PROGRAM_PATH = $(BUILD_PATH)/$(PROGRAM_NAME)
# Target to build main program                                               [X]
PROGRAM_TARGET = $(PROGRAM_PATH)
################################################################################
# LIBRARY COMMON
################################################################################
# 'foo' part in 'libfoo'                                                     [R]
LIB_NAME = $(PROJECT)
# Prefix of the headers/library install path                                 [R]
LIB_INSTALL_PREFIX := /usr/local
# Path where to install headers                                              [X]
HEADER_INSTALL_PATH = $(LIB_INSTALL_PREFIX)/include/$(LIB_NAME)
# Path where to install library                                              [X]
LIB_INSTALL_PATH = $(LIB_INSTALL_PREFIX)/lib/$(LIB_NAME)
################################################################################
# SHARED LIBRARY
################################################################################
# libfoo.so                                                                  [X]
LIB_SHARED = lib$(LIB_NAME).so
# libfoo.so.1                                                                [X]
LIB_SHARED_X = $(LIB_SHARED).$(VERSION_MAJOR)
# libfoo.so.1.2.3                                                            [X]
LIB_SHARED_XYZ = $(LIB_SHARED).$(VERSION)
# Output path for libfoo.so                                                  [X]
LIB_SHARED_PATH = $(BUILD_PATH)/$(LIB_SHARED)
# Output path for libfoo.so.1                                                [X]
LIB_SHARED_X_PATH = $(BUILD_PATH)/$(LIB_SHARED_X)
# Output path for libfoo.so.1.2.3                                            [X]
LIB_SHARED_XYZ_PATH = $(BUILD_PATH)/$(LIB_SHARED_XYZ)
# Target to build the shared lib                                             [X]
LIB_SHARED_TARGET = $(LIB_SHARED_XYZ_PATH)
################################################################################
# STATIC LIBRARY
################################################################################
# libfoo.a                                                                   [X]
LIB_STATIC = lib$(LIB_NAME).a
# Output path for libfoo.a                                                   [X]
LIB_STATIC_PATH = $(BUILD_PATH)/$(LIB_STATIC)
# Target to build the static lib                                             [X]
LIB_STATIC_TARGET = $(LIB_STATIC_PATH)
