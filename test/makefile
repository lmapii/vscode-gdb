# dummy MAKE

PROJECT_NAME := dummy

MODULES :=         \
    common         \
    dummy          \
    mockme

# TODO: CHECK THIS - change to you own settings (e.g., windows paths)
CC     = gcc
ECHO   = echo
MKDIR  = mkdir
RM     = rm
silent =@

# change this - then step-into any module won't work anymore
PRJ_ROOT := ../test/dev
PRJ_BLD  := ../test/bld
# PRJ_ROOT := dev
# PRJ_BLD  := bld

OBJ_PATH := $(PRJ_BLD)/obj
OUT_PATH := $(PRJ_BLD)/out

GEN_DIRS     = $(PRJ_BLD)
GEN_DIRS_SUB = $(OBJ_PATH) $(OUT_PATH)
OUTPUT_FILE  = $(OUT_PATH)/$(PROJECT_NAME)

# TODO: CHECK THIS - change this then the entry point won't work anymore
# CC_FILES  := ../test/test-dummy/test_dummy.c
CC_FILES  := test-dummy/test_dummy.c
INCDIRS   :=
OBJ_FILES :=

# simply include all source files for all modules
CC_FILES += $(foreach module, $(MODULES), $(wildcard $(PRJ_ROOT)/$(module)/*.c))

# and add the include directive
INCDIRS += $(foreach module, $(MODULES), -I $(PRJ_ROOT)/$(module))

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SKIP_FOR := clean
ifeq (,$(filter $(SKIP_FOR), $(MAKECMDGOALS)))
$(info .                                                 )

$(foreach dir, $(GEN_DIRS),\
    $(info create/update directory $(dir)) \
    $(eval $(shell $(MKDIR) -p $(dir) )) )

$(foreach dir, $(GEN_DIRS_SUB),\
    $(info create/update directory $(dir)) \
    $(eval $(shell $(MKDIR) -p $(dir) )) )
endif

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

.DEFAULT_GOAL := all
.PHONY: prebuild postbuild clean build

# build without project specific post-processing/rules
build: prebuild postbuild

# full build process
all : prebuild postbuild

prebuild :
	$(silent)$(ECHO) '** building project $(PROJECT_NAME)  '

postbuild : $(OUTPUT_FILE).out
	$(silent)$(ECHO) ""
	$(silent)$(ECHO) '*                                   '
	$(silent)$(ECHO) '* make done for $(PROJECT_NAME).    '

clean :
	$(silent)$(ECHO) "### removing directory $(GEN_PATH)"
	$(RM) -rf $(GEN_DIRS)

$(OUTPUT_FILE).out : $(CC_FILES)
	$(CC) -g $(INCDIRS) $(CC_FILES) -o $(OUTPUT_FILE).out
