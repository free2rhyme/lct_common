
ifndef $(LCT_SVC_PRJ_ROOT)
	CURR_DIR_PATH     := $(strip $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST)))))
	LAST_DIR_PATH     := $(shell dirname $(CURR_DIR_PATH))
	LAST_DIR_NAME     := $(notdir $(LAST_DIR_PATH))

ifeq ($(LAST_DIR_NAME), src)
	LCT_SVC_PRJ_ROOT  := $(shell dirname $(LAST_DIR_PATH))
	LCT_SVC_SRC_ROOT  := $(LCT_SVC_PRJ_ROOT)/src
else
	LCT_SVC_PRJ_ROOT  := $(CURR_DIR_PATH)
	LCT_SVC_SRC_ROOT  := $(LAST_DIR_PATH)
endif

endif

SRC_DIR           := detail
TARGET_TYPE       = lib
SRC_SUFFIX        = cpp
INC_DIR           += -I$(LCT_SVC_SRC_ROOT)/lct_common
SYS_LIB           += 
DEP_OBJ           +=
TARGET            := liblct_common.a

include $(LCT_SVC_SRC_ROOT)/lct_common/common.mk

