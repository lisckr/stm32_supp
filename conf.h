#ifndef _CONF_H
#define _CONF_H



/* ------------------------------------------------------------------------- */


#include "stm32f10x.h"
#include  "stdio.h"


/* ------------------------------------------------------------------------- */

#define USART1_Open   1    //串口一 启/停 标志  开启：1  关闭： 0
#define USART2_Open   0    //串口二 启/停 标志  开启：1  关闭： 0



#define DELAY_simp    0    //延时函数： 粗略型  开启：1  关闭:  0
#define DELAY_syst    1    //延时函数： Systic  开启：1  关闭:  0


#define EXIT_Open     0    


/* ------------------------------------------------------------------------- */


void delay_us(u32 sec);
void delay_ms(u32 sec);


void delay_init(void);
void delayus(u32 nus);
void delayms(u32 nms);


void NVIC_Config(void);


void EXIT_Config(void);


void PWM_Config(u16 period,u16 scale);


void USART1_Config(u32 bound);
void USART1_Send(u8 data);
void USART1_Print(char *str);
void USART1_Println(char *str);


void USART2_Config(u32 bound);
void USART2_Send(u8 data);
void USART2_Print(char *str);
void USART2_Println(char *str);


void USART3_Config(u32 bound);
void USART3_Send(u8 data);
void USART3_Print(char *str);
void USART3_Println(char *str);




#endif

