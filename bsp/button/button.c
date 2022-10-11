#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"


void gpio_init()
{
    // select input gpio pin
    GPIO_setPinConfig(GPIO_97_GPIO97);
    GPIO_setDirectionMode(97, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(97, GPIO_PIN_TYPE_PULLUP);  //  Pull-up enable for input
    GPIO_setMasterCore(97, GPIO_CORE_CPU1);

    // select output gpio pin

    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED2);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED2, GPIO_CORE_CPU1);

}




