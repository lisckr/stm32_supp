/**
  ******************************************************************************
  * @file    supp/usart.c 
  * @author  lisck
  * @version V1.0.1
  * @date    2016-02-18
  * @brief   USART1_Config()  USART1_Print()
  ******************************************************************************
  * @attention
  *  本演示部分代码，全部由  lisck 编写完成，请勿用于商业用途
  *  如遇到任何 技术问题 ，请 访问 http://www.lincy.cn  留言板留言
  *  QQ : 2318006530
  *  Email :  1@lincy.cn
  *
  ******************************************************************************
  */  


//  _Includes 

#include "conf.h"

//  _Defines



//  _Declare 





/* ------------------------------  支持 printf  ------------------------------*/


//勾选 Use MicroLIB   支持 printf 函数

int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}

    return ch;
}


/* ------------------------------- 串口一 配置 ------------------------------- */

#if USART1_Open

void USART1_Config(u32 bound)
{
  
  GPIO_InitTypeDef  GPIO_InitStructure; 
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1,ENABLE);
  
                                                
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;      //GPIO初始化  GPIOA->9  Mode->AF_PP  SPEED->50MHz
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;      //GPIO初始化  GPIOA->10 Mode->IN_FLOATING
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA,&GPIO_InitStructure);         
  
  
  
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;      //NVIC初始化
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  USART_InitStructure.USART_BaudRate = bound;                  //USART初始化  WordLength->8   HardwareFlow->None  
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;  //   Mode->Tx/Rx  Parity->None  StopBit->1
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART1,&USART_InitStructure);
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
  USART_Cmd(USART1,ENABLE);                                  
    
}

#endif


/* ------------------------------- 串口二 配置 ------------------------------- */

#if USART2_Open

void USART2_Config(u32 bound)
{
     
  GPIO_InitTypeDef  GPIO_InitStructure; 
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA,&GPIO_InitStructure);
  
  
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;      
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  USART_InitStructure.USART_BaudRate = bound;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART2,&USART_InitStructure);
  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
  USART_Cmd(USART2,ENABLE);
  
}

#endif



/* ------------------------------- 串口三 配置 ------------------------------- */

#if USART3_Open

void USART3_Config(u32 bound)
{
     
  GPIO_InitTypeDef  GPIO_InitStructure; 
  NVIC_InitTypeDef  NVIC_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB,&GPIO_InitStructure);
  
  
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;      
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  
  USART_InitStructure.USART_BaudRate = bound;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;

  USART_Init(USART3,&USART_InitStructure);
  USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
  USART_Cmd(USART3,ENABLE);
  
}

#endif





/* ------------------------------- 中断处理函数 ------------------------------ */

//串口1中断接收
#if USART1_Open

void USART1_IRQHandler(void)             
{
  u8 size = 0;
//  char *ff;
  char USART1_Buff[]= {0};
  
  if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) != RESET)
  {
    USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
    USART1_Buff[size] = (char)USART_ReceiveData(USART1);
    
    if( USART1_Buff[size] == '\0')
		   {  			
//			   ff = USART1_Buff;
//         USART1_Println(ff);
				 size = 0;
			   USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);	
			   }
  }
}

#endif



//串口2中断接收
#if USART2_Open

void USART2_IRQHandler(void)             
{
  u8 size = 0;
  char *ff;
  char USART2_Buff[]= {0};
  
  if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != RESET)
  {
    USART_ITConfig(USART2, USART_IT_RXNE, DISABLE);
    USART2_Buff[size] = (char)USART_ReceiveData(USART2);
    
    if( USART2_Buff[size] == '\0')
		   {  			
			   ff = USART2_Buff;
//       USART1_Println(ff);
				 size = 0;
			 	 USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);	
			   }
  }
}

#endif



//串口3中断接收
#if USART3_Open

void USART3_IRQHandler(void)             
{
  u8 size = 0;
  char *ff;
  char USART3_Buff[]= {0};
  
  if(USART_GetFlagStatus(USART3,USART_FLAG_RXNE) != RESET)
  {
    USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
    USART3_Buff[size] = (char)USART_ReceiveData(USART3);
    
    if( USART3_Buff[size] == '\0')
		   {  			
			   ff = USART3_Buff;
//       USART1_Println(ff);
				 size = 0;
			 	 USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);	
			   }
  }
}

#endif



/* ----------------------------  数据 发送/接收  -----------------------------*/

//USART1 单字节发送
void USART1_Send(u8 data)
{
  USART_ClearFlag(USART1,USART_FLAG_TC);
  USART_SendData(USART1,data);
  while( USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
  USART_ClearFlag(USART1,USART_FLAG_TC);
}

//USART2 单字节发送
void USART2_Send(u8 data)
{
  USART_ClearFlag(USART2,USART_FLAG_TC);
  USART_SendData(USART2,data);
  while( USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);
  USART_ClearFlag(USART2,USART_FLAG_TC);
}

//USART3 单字节发送
void USART3_Send(u8 data)
{
  USART_ClearFlag(USART3,USART_FLAG_TC);
  USART_SendData(USART3,data);
  while( USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);
  USART_ClearFlag(USART3,USART_FLAG_TC);
}

/* ------------------------------------------------------------------------- */


//USART1 发送字符串
void USART1_Print(char *str)
{
  while(*str)
  {
    USART1_Send(*str++);
  }
}

//USART2 发送字符串
void USART2_Print(char *str)
{
  while(*str)
  {
    USART2_Send(*str++);
  }
}

//USART3 发送字符串
void USART3_Print(char *str)
{
  while(*str)
  {
    USART3_Send(*str++);
  }
}

/* ------------------------------------------------------------------------- */

//USART1 发送字符串 结束换行
void USART1_Println(char *str)
{
  while(*str)
  {
    USART1_Send(*str++);
  }
  USART1_Send('\n');
}

//USART2 发送字符串 结束换行
void USART2_Println(char *str)
{
  while(*str)
  {
    USART2_Send(*str++);
  }
  USART2_Send('\n');
}

//USART3 发送字符串 结束换行
void USART3_Println(char *str)
{
  while(*str)
  {
    USART3_Send(*str++);
  }
  USART3_Send('\n');
}









/* -------------------------------  end code  --------------------------------*/



 





























