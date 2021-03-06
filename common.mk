######################################################################
 # @copyright    Copyright (C), 2017
 # @file         common.mk
 # @version      1.0
 # @date         Jun 8, 2017 5:18:16 PM
 # @author       wlc2rhyme@gmail.com
 # @brief        TODO
 #####################################################################

CXX             = g++
CPP_FLAGS_3RD   = -g -O3 --std=c++11
CPP_FLAGS_LOOSE = -g -O1 -Wall -Wextra -Werror -Wredundant-decls -Wno-unused-parameter -Wno-shadow --std=c++11
CPP_FLAGS_LCT   = -g -O3 -Wall -Wextra -Werror -Wcast-qual -Wredundant-decls -Wno-unused-parameter -Wno-shadow --std=c++11

ifeq ($(CPP_FLAG_VERSION), 3rd)
    CPP_FLAGS   := $(CPP_FLAGS_3RD)
else ifeq ($(CPP_FLAG_VERSION), loose)
    CPP_FLAGS   := $(CPP_FLAGS_3RD)
else
    CPP_FLAGS   := $(CPP_FLAGS_LCT)
endif

ifndef SRC_DIR
SRC_DIR := ./
endif

VPATH           := $(SRC_DIR)
CPPS            := $(foreach dir, $(VPATH), $(wildcard $(dir)/*.$(SRC_SUFFIX)))
OBJS            := $(patsubst %.$(SRC_SUFFIX), %.o, $(notdir $(CPPS)))
DEPS            := $(patsubst %.$(SRC_SUFFIX), %.d, $(notdir $(CPPS)))

ifeq ($(SRC_POST_PATH), )
CURR_BASE_DIR   := $(notdir $(CURR_DIR_PATH))
else
CURR_BASE_DIR   := $(SRC_POST_PATH)
endif

BUILD_OBJ_ROOT  := $(LCT_SVC_PRJ_ROOT)/build/obj

BUILD_OBJ_DIR   := $(BUILD_OBJ_ROOT)/$(CURR_BASE_DIR)

LIB_DIR         := $(LCT_SVC_PRJ_ROOT)/build/lib

ifeq ($(TARGET_TYPE), app)
    FIXED_TARGET_DIR    := $(LCT_SVC_PRJ_ROOT)/build/bin
else ifeq ($(TARGET_TYPE), lib)
    FIXED_TARGET_DIR    := $(LCT_SVC_PRJ_ROOT)/build/lib
else
    FIXED_TARGET_DIR    := $(BUILD_OBJ_DIR)
endif

FIXED_TARGET    := $(addprefix $(FIXED_TARGET_DIR)/, $(TARGET))
FIXED_OBJS      := $(addprefix $(BUILD_OBJ_DIR)/, $(OBJS))
FIXED_DEPS      := $(addprefix $(BUILD_OBJ_DIR)/, $(DEPS))

all debug release build:$(FIXED_OBJS)
ifneq ($(FIXED_TARGET_DIR), $(wildcard $(FIXED_TARGET_DIR)))
	@mkdir -p $(FIXED_TARGET_DIR)
endif

	@echo 'Building target: $@'
ifeq ($(TARGET_TYPE), app)
	$(CXX) $^ $(DEP_OBJ) $(SYS_LIB_DIR) $(SYS_LIB) -o $(FIXED_TARGET) 
else ifeq ($(TARGET_TYPE), lib)
	ar -r $(FIXED_TARGET) $(FIXED_OBJS)
else 
.PHONY: $(TARGET)
endif
	@echo 'Finished building target: $@'
	@echo ' '

-include $(FIXED_DEPS)

$(BUILD_OBJ_DIR)/%.o:%.$(SRC_SUFFIX)
ifneq ($(BUILD_OBJ_DIR), $(wildcard $(BUILD_OBJ_DIR)))
	@mkdir -p $(BUILD_OBJ_DIR)
endif

	@echo "Start building $@"
	$(CXX) $(CPP_FLAGS) $(INC_DIR) -o $@ -c $< -MMD -MF"$(@:%.o=%.d)"
	@echo "Finished building $@"
	@echo " "

clean: cleanObj
	rm -fr $(FIXED_TARGET_DIR)
	rm -fr $(BUILD_OBJ_DIR)
	rm -fr $(BUILD_OBJ_ROOT)
	@echo " "

cleanObj:
	rm -fr $(BUILD_OBJ_DIR)/*
	rm -f $(FIXED_OBJS)
	rm -f $(FIXED_DEPS)
	rm -f $(FIXED_TARGET)
	@echo " "

rebuild:cleanObj all

.PHONY:clean cleanObj rebuild


