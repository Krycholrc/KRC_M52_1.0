BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp \
    $(BOARD_DIR)/default_tune.cpp \


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# Override DEFAULT_ENGINE_TYPE
DDEFS += -DSTM32F407xx
DDEFS += -DFIRMWARE_ID=\"KRC_M52\"
DDEFS += -DHAL_TRIGGER_USE_PAL=TRUE

# reduce memory usage monitoring
DDEFS += -DRAM_UNUSED_SIZE=100

# assign critical LED to a non-existent pin if you do not have it on your board
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::Unassigned

# Enable specific features for the board
DDEFS += -DSTM32_ADC_USE_ADC2=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE
