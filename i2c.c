/**
  ******************************************************************************
  * @file    supp/i2c.c 
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



/* ----------------------------------------------------------------------------*/

// i2c 初始化
void I2C1_Config(void)
{
  
  GPIO_InitTypeDef GPIO_InitStructure;
  I2C_InitTypeDef   I2C_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
  
  
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_OD;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);
  
  I2C_InitStructure.I2C_ClockSpeed = 100000;      //时钟速度  0-400k
  I2C_InitStructure.I2C_Mode       = I2C_Mode_I2C;
  I2C_InitStructure.I2C_DutyCycle  = I2C_DutyCycle_2;
  I2C_InitStructure.I2C_Ack        = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_Init(I2C1,&I2C_InitStructure);
  
  I2C_Cmd(I2C1,ENABLE);
  
}


/* ----------------------------------------------------------------------------*/

// I2C 查地址 写数据
void I2C1_Write(u8 id,u8 address,u8 byte)
{

  I2C_GenerateSTART(I2C1, ENABLE);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));  
  
  I2C_Send7bitAddress(I2C1,id, I2C_Direction_Transmitter); 
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ));  
  
  I2C_SendData(I2C1, address);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTING));    
  
  I2C_SendData(I2C1,byte);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));    
  
  I2C_GenerateSTOP(I2C1,ENABLE);

}

/* ----------------------------------------------------------------------------*/

// I2C 查地址 读数据
u8 I2C1_Read(u8 id,u8 address)
{
  u8 temp;

  I2C_GenerateSTART(I2C1, ENABLE);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
  
  I2C_AcknowledgeConfig(I2C1, DISABLE); 
  I2C_Send7bitAddress(I2C1,id,I2C_Direction_Transmitter);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  
  I2C_SendData(I2C1,address);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTING));
  
  I2C_GenerateSTART(I2C1,ENABLE);      
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT)); 
  
  I2C_Send7bitAddress( I2C1,id, I2C_Direction_Receiver);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)); 
  
  I2C_GenerateSTOP(I2C1,ENABLE);
  while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED)); 
  
  temp=I2C_ReceiveData(I2C1);

  return temp;
}





/* -------------------------------  end code  --------------------------------*/
