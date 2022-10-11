/*
 * led.c
 *
 *  Created on: 2022年7月10日
 *      Author: sqxqian
 */
#include "led.h"

void led_Init(void)
{
    /*寄存器配置*/
    EALLOW;

    /*配置输出管脚IO31*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO31=0;
    GpioCtrlRegs.GPAPUD.bit.GPIO31=0;
    GpioCtrlRegs.GPADIR.bit.GPIO31=1;

    /*配置输出管脚IO34*/
    GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;
    GpioCtrlRegs.GPBPUD.bit.GPIO34=0;
    GpioCtrlRegs.GPBDIR.bit.GPIO34=1;

    EDIS;

//    /*库函数配置*/
//    /*LED1*/
//    GPIO_setPinConfig(DEVICE_GPIO_CFG_LED1);
////    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED1, GPIO_CORE_CPU1);
//    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
//    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);
//    /*LED2*/
//    GPIO_setPinConfig(DEVICE_GPIO_CFG_LED2);
////    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED2, GPIO_CORE_CPU1);
//    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
//    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);

    /*LED1\LED2初始状态为灭*/
    GpioDataRegs.GPADAT.bit.GPIO31 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO34 = 1;
}

void LED1_bright(void)
{
    GpioDataRegs.GPADAT.bit.GPIO31 = 0;
}
void LED1_extinguish(void)
{
    GpioDataRegs.GPADAT.bit.GPIO31 = 1;
}

void LED2_bright(void)
{
    GpioDataRegs.GPBDAT.bit.GPIO34 = 0;
}
void LED2_extinguish(void)
{
    GpioDataRegs.GPBDAT.bit.GPIO34 = 1;
}

/*LED1\LED2跳转*/
void LED1_Toggle(void)
{
    GPIO_togglePin(DEVICE_GPIO_PIN_LED1);
    DEVICE_DELAY_US(500000);
}
void LED2_Toggle(void)
{
    GPIO_togglePin(DEVICE_GPIO_PIN_LED2);
    DEVICE_DELAY_US(500000);
}

