/**
  ******************************************************************************
  * @file    supp/delay.c 
  * @author  lisck
  * @version V1.0.1
  * @date    2016-02-18
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

static u8  fac_us=0;
static u16 fac_ms=0;

//  _Declare 



/* ------------------------------  粗略型延时  -------------------------------*/

//粗略型 延时
#if DELAY_simp

//微秒 延时
void delay_us(u32 sec)
{
  u16 i=0;
  while(sec--)
  {
    i=10;
    while(i--);
  }  
}

/* ------------------------------------------------------------------------- */

//毫秒 延时
void delay_ms(u32 sec)
{
  u16 i=0;
  while(sec--)
    {
      i=12000;
      while(i--);
    }
}

#endif


/* -----------------------------  滴答时钟延时  ------------------------------*/

#if DELAY_syst




//延迟函数初始化
void delay_init(void)	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	  //选择外部时钟  HCLK/8
	fac_us=SystemCoreClock/8000000;	                        //系统时钟的1/8  
	fac_ms=(u16)fac_us*1000;  
}								    

/* ------------------------------------------------------------------------- */

//微秒级 延时
void delayus(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us;                             	 
	SysTick->VAL=0x00;                                    
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;               
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));                       
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;              
	SysTick->VAL =0X00;                                    
}

/* ------------------------------------------------------------------------- */

//毫秒级 延时
void delayms(u32 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;                       
	SysTick->VAL =0x00;                                   
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;              
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));                    
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;              
	SysTick->VAL =0X00;                                   	    
} 


#endif






/* -------------------------------  end code  --------------------------------*/
