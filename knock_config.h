/**
 * @file knock_config.h
 */

#pragma once

// Knock is on ADC2
#define KNOCK_ADC ADCD2

// knock 1 - pin PC5
#define KNOCK_ADC_CH1 ADC_CHANNEL_IN15
#define KNOCK_PIN_CH1 Gpio::C5

// knock 2 - pin PB0
//#define KNOCK_HAS_CH2 true
//#define KNOCK_ADC_CH2 ADC_CHANNEL_IN8
//#define KNOCK_PIN_CH2 Gpio::B0

// Sample rate & time - depends on the exact MCU
#define KNOCK_SAMPLE_TIME ADC_SAMPLE_84
#define KNOCK_SAMPLE_RATE (STM32_PCLK2 / (4 * (84 + 12)))
