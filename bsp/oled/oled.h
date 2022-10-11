
#ifndef BSP_OLED_OLED_H_
#define BSP_OLED_OLED_H_

#include "driverlib.h"
#include "device.h"

#include "stdlib.h"
#define u8 char
#define u32 long
#define u16 int
//-----------------OLED端口定义----------------

//#define PIN_SCL    GPIO0
//#define PIN_SDA    GPIO1

//#define PIN_LCD_CS              61
//#define PIN_CS                  GPIO_61_GPIO61
//
//#define PIN_LCD_RST             123
//#define PIN_RST                 GPIO_123_GPIO123

#define OLED_SCL_Clr()   GPIO_writePin(105, 0);
#define OLED_SCL_Set()   GPIO_writePin(105, 1);

#define OLED_SDA_Clr()   GPIO_writePin(104, 0);
#define OLED_SDA_Set()   GPIO_writePin(104, 1);



#define OLED_CMD  0 //写命令
#define OLED_DATA 1 //写数据

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);
void DELAY_MS(int x);
void show_floatnum(int x,int y,float num);
void show_guiyinum(float num[6]);





#endif /* BSP_OLED_OLED_H_ */
