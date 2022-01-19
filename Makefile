# SPDX-License-Identifier: 0BSD
################################################################################
# CTL
################################################################################
MAKEFILE_PATH := makefiles
include $(MAKEFILE_PATH)/config.mk
PROJECT := ctl
PROJECT_TYPE := header
################################################################################
# TARGETS
################################################################################
# Default targets
include $(MAKEFILE_PATH)/targets.mk

#$(info $(.FEATURES))
#$(info $(.INCLUDE_DIRS))
#$(info $(.EXTRA_PREREQS))
#$(info $(.VARIABLES))
#$(info $(.RECIPEPREFIX))
#$(info $(MAKE_TERMERR))
#$(info $(.DEFAULT_GOAL))
#$(info $(MAKEFILE_LIST))
#$(info $(MAKEFLAGS))
#$(info $(MAKECMDGOALS))
#$(info $(.SHELLFLAGS))
#$(info $(SHELL))
