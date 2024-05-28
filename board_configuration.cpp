#include "pch.h"

static void setInjectorPins() {
	
	engineConfiguration->injectionPinMode = OM_DEFAULT;

	engineConfiguration->injectionPins[0] = Gpio::C6;
	engineConfiguration->injectionPins[1] = Gpio::D8;
	engineConfiguration->injectionPins[2] = Gpio::D14;
	engineConfiguration->injectionPins[3] = Gpio::D12;
	engineConfiguration->injectionPins[4] = Gpio::D15;
	engineConfiguration->injectionPins[5] = Gpio::D13;
}

static void setIgnitionPins() {
	
	engineConfiguration->ignitionPinMode = OM_DEFAULT;

	engineConfiguration->ignitionPins[0] = Gpio::E2;
	engineConfiguration->ignitionPins[1] = Gpio::E3;
	engineConfiguration->ignitionPins[2] = Gpio::C13;
	engineConfiguration->ignitionPins[3] = Gpio::E6;
	engineConfiguration->ignitionPins[4] = Gpio::E4;
	engineConfiguration->ignitionPins[5] = Gpio::E5;
}

void setBoardConfigOverrides(void) {
	// Throttle #1
	// PWM pin
	engineConfiguration->etbIo[0].controlPin = Gpio::Unassigned;
	// DIR pin
	engineConfiguration->etbIo[0].directionPin1 = Gpio::Unassigned;
	// Disable pin
	engineConfiguration->etbIo[0].disablePin = Gpio::Unassigned;
	// Unused
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;

	// Throttle #2
	// PWM pin
	engineConfiguration->etbIo[1].controlPin = Gpio::Unassigned;
	// DIR pin
	engineConfiguration->etbIo[1].directionPin1 = Gpio::Unassigned;
	// Disable pin
	engineConfiguration->etbIo[1].disablePin = Gpio::Unassigned;
	// Unused
	engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;

	engineConfiguration->etb_use_two_wires = false;
	
	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;

	engineConfiguration->baroSensor.hwChannel = EFI_ADC_5;

	engineConfiguration->lps25BaroSensorScl = Gpio::Unassigned;
	engineConfiguration->lps25BaroSensorSda = Gpio::Unassigned;

	engineConfiguration->afr.hwChannel = Gpio::Unassigned;
}

void setPinConfigurationOverrides(void) {

	//CAN 1 bus overwrites
	engineConfiguration->canTxPin = Gpio::Unassigned;
	engineConfiguration->canRxPin = Gpio::Unassigned;

	//CAN 2 bus overwrites
	engineConfiguration->can2RxPin = Gpio::Unassigned;
	engineConfiguration->can2TxPin = Gpio::Unassigned;
}

static void setupVbatt() {
	
    engineConfiguration->analogInputDividerCoefficient = 1.52f;
    engineConfiguration->vbattDividerCoeff = (7.55f / 1.0f);
    engineConfiguration->vbattAdcChannel = EFI_ADC_4;
    engineConfiguration->adcVcc = 3.24f;
}

Gpio getCommsLedPin() {
    return Gpio::Unassigned;
}
Gpio getRunningLedPin() {
    return Gpio::Unassigned;
}
Gpio getWarningLedPin() {
    return Gpio::Unassigned;
}

void setBoardDefaultConfiguration(void) {
	
	setInjectorPins();
	setIgnitionPins();
	setupVbatt();	

	engineConfiguration->isSdCardEnabled = true;

        engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled = true;
	engineConfiguration->canSleepPeriodMs = 50;

	engineConfiguration->canBaudRate = B1MBPS;
	engineConfiguration->can2BaudRate = B500KBPS;
	

}
