/**
  ******************************************************************************
  * Ten Tep          :     user_usart.c
  * Tac Gia          :     Nguyen Quy Nhat
  * Cong Ty          :     MinhHaGroup
  * Website          :     MinhHaGroup.com
  * Phien Ban        :     V1.0.0
  * Ngay             :     31-07-2012
  * Tom Tat          :     Dinh nghia cac ham duoc su dung de dieu khien khoi USART.					          			
  *           				
  *
  ******************************************************************************
  * Chu Y						 :				
	*										+ Tuy theo muc dich su dung ma lua chon cac cau hinh cho 			
  *											phu hop.
	*										+ Phai cau hinh GPIO la cac chan USART tuong ung tai 
	*											file user_gpio.c
	*										+ Neu su dung them cac chuc nang interrupt, dma...
	*											thi ta phai cau hinh cho cac chuc nang do dua vao
	*											cac file tuong ung can su dung (user_nvic, user_interrupt
	*                     , user_dma.....);
	*										+ Mot so cau hinh, chuc nang co the khong duoc su dung trong
	*											mot bo USART, de biet chi tiet xem tai file stm32f10x_usart.c
	*										+ file nay cau hinh cho USART 1,2,3. Neu su dung cac USART
	*											khac ta se khai bao, dinh nghia tuong tu cac ham dua theo 
	*                     cac USART tuong ung.
	*
  *
  * 
  ******************************************************************************
  */
#include "user_usart.h"

u8 uart1Buffer[BUFF_SIZE], i = 0, data1[BUFF_SIZE];

//void USART1_IRQHandler(void)
//{
//	if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
//	{
////		USART_ClearFlag(USART1, USART_FLAG_RXNE); 
//		uart1Buffer[i] = USART_ReceiveData(USART1) & 0x7F;
//		i++;
//	}
//	if(USART_GetFlagStatus(USART1, USART_FLAG_IDLE) != RESET)
//	{
//		i = 0;
//		memset(data1, '\0', BUFF_SIZE);
//		strcpy((char*)data1, (char*)uart1Buffer);
//		memset(uart1Buffer, '\0', BUFF_SIZE);
////		DMA_M2M_TranferByte(uart1Buffer, data1, BUFF_SIZE);
//		USART_SendString(USART1, (char*)data1);
//	}
//}

void USART1_Configuration(u32 baudrate)									
{

	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	         		 //USART1 TX
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    		 //
	GPIO_Init(GPIOA, &GPIO_InitStructure);		    		       //
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_8;	         	 //USART1 RX
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   	 //
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = baudrate;									//9600, 19200, 115200, ...
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		// USART_WordLength_8b:8 bits, USART_WordLength_9b: 9bits
	USART_InitStructure.USART_StopBits = USART_StopBits_2;			// 1 stop, USART_StopBits_0_5;USART_StopBits_1_5;USART_StopBits_2
	USART_InitStructure.USART_Parity = USART_Parity_No;				// USART_Parity_Even; USART_Parity_Odd 
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //USART_HardwareFlowControl_RTS;USART_HardwareFlowControl_CTS;USART_HardwareFlowControl_RTS_CTS
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//
	USART_Init(USART1, &USART_InitStructure);											 //
	
//	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_Init(&NVIC_InitStructure);

//	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  
//	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE); 
	//USART_ITConfig(USART1, USART_IT_TXE, ENABLE);						//
	//USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
	//USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);

	USART_Cmd(USART1, ENABLE);	
}
void USART2_Configuration(USART_TypeDef* USARTx)									
{
	USART_InitTypeDef USART_InitStructure;
	//Kich hoat Clock USART2
	RCC_APB2PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE);
	USART_InitStructure.USART_BaudRate = 9600;						//9600, 19200, 115200
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;		// 8 bit, USART_WordLength_9b: 9bit
	USART_InitStructure.USART_StopBits = USART_StopBits_1;			// 1 stop, USART_StopBits_0_5;USART_StopBits_1_5;USART_StopBits_2
	USART_InitStructure.USART_Parity = USART_Parity_No;				// USART_Parity_Even; USART_Parity_Odd   
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //USART_HardwareFlowControl_RTS;USART_HardwareFlowControl_CTS;USART_HardwareFlowControl_RTS_CTS
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//

	/* Configure USARTx */
	USART_Init(USARTx, &USART_InitStructure);							//


	/* Enable USARTx Receive and Transmit interrupts */
	USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);       
	USART_ITConfig(USARTx, USART_IT_TXE, ENABLE);			

	/* Enable the USARTx */
	USART_Cmd(USARTx, ENABLE);	
}
void USART_SendChar(USART_TypeDef* USARTx, u8 data)
{
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET)
	{}	
	USART_SendData(USARTx,data);
}
void USART_SendString(USART_TypeDef* USARTx, char *str)
{
	while (*str)
	{
		USART_SendChar(USARTx,*str); 
		str++;
	}
}


