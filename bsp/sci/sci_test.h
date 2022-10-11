/*
 * sci_test.h
 *
 *  Created on: Aug 29, 2022
 *      Author: DELL
 */

#ifndef BSP_SCI_SCI_TEST_H_
#define BSP_SCI_SCI_TEST_H_
#include "driverlib.h"
#include "device.h"
#include "stdlib.h"



#define    EMPTY_LOOP
#define    ENDLESS    1

void UART_GPIO_init(void);
void SCI_A_init(void);
void uart_tx_bite(uint16_t a);
void hal_PutsUART(char * s);
void scia_xmit(int a);
void scia_fifo_init();
void scia_msg(char * msg);

#endif /* BSP_SCI_SCI_TEST_H_ */
