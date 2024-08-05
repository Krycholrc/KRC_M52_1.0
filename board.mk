# List of all the board related files.
BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# Override DEFAULT_ENGINE_TYPE
DDEFS += -DSTM32F407xx
DDEFS += -DFIRMWARE_ID=\"KRC_ECU8\"
DDEFS += -DHAL_TRIGGER_USE_PAL=TRUE

# Knock
DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE

# reduce memory usage monitoring
DDEFS += -DRAM_UNUSED_SIZE=100

# Critical LED (Err)
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::E8
