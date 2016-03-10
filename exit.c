/**
  ******************************************************************************
  * @file    supp/exit.c 
  * @author  lisck
  * @version V1.0.1
  * @date    2016-02-19
  * @brief   
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




/* ------------------------------  中断初始化  --------------------------------*/

#if  EXIT_Open

void EXIT_Config(void)
{
  
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef  NVIC_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  
  

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);  // A-G  0-15  
  EXTI_InitStructure.EXTI_Line    = EXTI_Line0;               //中断线路选择 0-15
  EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
  
 
  NVIC_InitStructure.NVIC_IRQChannel =EXTI0_IRQHandler;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
}

#endif



/* ------------------------------  中断处理函数  ------------------------------*/

#if  EXIT_Open

void EXTI0_IRQHandler(void)
{
  
  delay_ms(10);        //消抖
  if(1)   
  {	  
    
  }
  EXTI_ClearITPendingBit(EXTI_Line0);  
  
}

#endif









/* -------------------------------  end code  --------------------------------*/
