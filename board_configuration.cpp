#include "pch.h"

Gpio getCommsLedPin() {
    return Gpio::Unassigned;
}
Gpio getRunningLedPin() {
    return Gpio::Unassigned;
}
Gpio getWarningLedPin() {
    return Gpio::Unassigned;
}

void setBoardDefaultConfiguration() {

	//Injector output
	engineConfiguration->injectionPinMode = OM_DEFAULT;
	engineConfiguration->injectionPins[0] = Gpio::D8;
	engineConfiguration->injectionPins[1] = Gpio::D9;
	engineConfiguration->injectionPins[2] = Gpio::D10;
	engineConfiguration->injectionPins[3] = Gpio::D11;
	engineConfiguration->injectionPins[4] = Gpio::D12;
	engineConfiguration->injectionPins[5] = Gpio::D13;
	engineConfiguration->injectionPins[6] = Gpio::D14;
	engineConfiguration->injectionPins[7] = Gpio::D15;

        //Ignition output
	engineConfiguration->ignitionPinMode = OM_DEFAULT;
	engineConfiguration->ignitionPins[0] = Gpio::E0;
	engineConfiguration->ignitionPins[1] = Gpio::E1;
	engineConfiguration->ignitionPins[2] = Gpio::E2;
	engineConfiguration->ignitionPins[3] = Gpio::E3;
	engineConfiguration->ignitionPins[4] = Gpio::E4;
	engineConfiguration->ignitionPins[5] = Gpio::E5;
	engineConfiguration->ignitionPins[6] = Gpio::E6;
	engineConfiguration->ignitionPins[7] = Gpio::E7;

	//Digital out
	engineConfiguration->fuelPumpPin = Gpio::E11;
	engineConfiguration->tachOutputPin = Gpio::D7;

	//Analog
	engineConfiguration->iat.adcChannel = EFI_ADC_0;
	engineConfiguration->clt.adcChannel = EFI_ADC_1;
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_6;
	engineConfiguration->vbattAdcChannel = EFI_ADC_4;
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;
	engineConfiguration->baroSensor.hwChannel = EFI_ADC_5;

	engineConfiguration->map.sensor.type = MT_MPXH6400;
	engineConfiguration->baroSensor.type = MT_MPXH6400;

	//Trigger 
	engineConfiguration->triggerInputPins[0] = Gpio::D3;
	engineConfiguration->camInputs[0] = Gpio::D4;

	//Bias resistor
	engineConfiguration->clt.config.bias_resistor = 2200;
	engineConfiguration->iat.config.bias_resistor = 2200;

	//Analog calc
        engineConfiguration->analogInputDividerCoefficient = 1.52f;
        engineConfiguration->vbattDividerCoeff = (7.55f / 1.0f);
        engineConfiguration->adcVcc = 3.24f;

	// SPI1 AUX
	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->max31855spiDevice = SPI_DEVICE_1;
	engineConfiguration->spi1mosiPin = Gpio::B5;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1sckPin = Gpio::B3;

	// SPI2 EGT
	engineConfiguration->is_enabled_spi_2 = true;
	engineConfiguration->max31855spiDevice = SPI_DEVICE_2;
	engineConfiguration->spi1mosiPin = Gpio::Unassigned;
	engineConfiguration->spi1misoPin = Gpio::B14;
	engineConfiguration->spi1sckPin = Gpio::B13;
	engineConfiguration->max31855_cs[0] = Gpio::B12;

        //SPI3 SD card
	engineConfiguration->isSdCardEnabled = true;
	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->spi3mosiPin = Gpio::C10;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3sckPin = Gpio::C12;
	engineConfiguration->sdCardCsPin = Gpio::D2;
	engineConfiguration->sdCardLogFrequency = 20;

	//CAN bus overwrites
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;
        engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled = true;
	engineConfiguration->canSleepPeriodMs = 50;
	engineConfiguration->canBaudRate = B500KBPS;

	//Engine configuration
	engineConfiguration->cylindersCount = 8;
	engineConfiguration->firingOrder = FO_1_5_4_8_6_3_7_2;
	engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;
	engineConfiguration->crankingInjectionMode = IM_SEQUENTIAL;
	engineConfiguration->injectionMode = IM_SEQUENTIAL;
	

}
