/*
 * led.h
 *
 *  Created on: 2022Äê7ÔÂ10ÈÕ
 *      Author: sqxqian
 */

#ifndef BSP_LED_LED_H_
#define BSP_LED_LED_H_

#include "F2837xD_Ipc_drivers.h"
#include "driverlib.h"
#include "device.h"

void led_Init(void);

void LED1_bright(void);

void LED1_extinguish(void);

void LED2_bright(void);

void LED2_extinguish(void);

void LED1_Toggle(void);

void LED2_Toggle(void);


#endif /* BSP_LED_LED_H_ */
