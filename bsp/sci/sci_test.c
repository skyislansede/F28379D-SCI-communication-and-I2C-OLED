
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"
#include "sci_test.h"


void UART_GPIO_init(){

        //SCIC -> SCI0 Pinmux
    GPIO_setPinConfig(GPIO_43_SCIRXDA);
    GPIO_setPinConfig(GPIO_42_SCITXDA);


}




void SCI_A_init(){

    SCI_performSoftwareReset(SCIA_BASE);

       SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, 115200, (SCI_CONFIG_WLEN_8 |
                                                SCI_CONFIG_STOP_ONE |
                                                SCI_CONFIG_PAR_NONE));
       SCI_resetChannels(SCIA_BASE);
       SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXRDY | SCI_INT_RXRDY_BRKDT);
       SCI_enableModule(SCIA_BASE);
       SCI_performSoftwareReset(SCIA_BASE);

       //
       // Enable the TXRDY and RXRDY interrupts.
       //
       SCI_enableInterrupt(SCIA_BASE, SCI_INT_TXRDY | SCI_INT_RXRDY_BRKDT);

   #ifdef AUTOBAUD
       //
       // Perform an autobaud lock.
       // SCI expects an 'a' or 'A' to lock the baud rate.
       //
       SCI_lockAutobaud(SCIA_BASE);
   #endif
}
//
// scia_xmit - Transmit a character from the SCI
//
void scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF.all =a;
}

//
// scia_msg - Transmit message via SCIA
//
void scia_msg(char * msg)
{
    int i;
    i = 0;
    while(msg[i] != '\0')
    {
        scia_xmit(msg[i]);
        i++;
    }
}
//
// scia_fifo_init - Initialize the SCI FIFO
//
void scia_fifo_init()
{
    ScicRegs.SCIFFTX.all = 0xE040;
    ScicRegs.SCIFFRX.all = 0x2044;
    ScicRegs.SCIFFCT.all = 0x0;
}




