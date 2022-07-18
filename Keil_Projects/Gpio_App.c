#include "Gpio.h"

const Port_ConfigType aPort_Config[CONFIGURED_PINS];

int main(void)
{
	Port_Init(aPort_Config);
}
