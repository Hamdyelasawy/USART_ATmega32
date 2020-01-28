/*
 * ATmega32A_USART.h
 *
 * Created: 6/14/2019 11:39:32 AM
 *  Author: Hamdy
 */ 


#ifndef ATMEGA32A_USART_H_
#define ATMEGA32A_USART_H_

	#include "StdTypes.h"
	

	typedef enum
	{
		USART_SingleProccesor,
		USART_MultiProcessor,
	}USART_CommunicationTerminal;

	typedef enum
	{
		USART_Async_NormalSpeed,
		USART_Async_DoubleSpeed,
		USART_Sync_Master,
		USART_Sync_Slave,
	}USART_CommunicationType;

	typedef enum
	{
		USART_Disable,
		USART_TX_Only,
		USART_RX_Only,
		USART_TX_RX,
	}USART_EnableMode;

	typedef enum
	{
		USART_NoError,
		USART_DataOverRunError,
		USART_FrameError,
		USART_ParityError,
		USART_InvaliedInit,
		USART_InvalidParamter,
		USART_InvalidInterruptSource,
	}USART_ErrorTypes;

	typedef enum
	{
		USART_DisableInterrupts,
		USART_RXComp_Enable,
		USART_TXComp_Enable,
		USART_DataEmpty_Enable,
		USART_RXComp_TXComp_Enable,
		USART_RXComp_DataEmpty_Enable,
		USART_TXComp_DataEmpty_Enable,
		USART_RXComp_TXComp_DataEmpty_Enable,
	}USART_InterruptSource;


	typedef enum
	{
		USART_5BitData,
		USART_6BitData,
		USART_7BitData,
		USART_8BitData,
		USART_9BitData,
	}USART_DataFrame;

	typedef enum
	{
		USART_ParityDisabled_1StopBit,
		USART_ParityDisabled_2StopBit,
		USART_ParityEven_1StopBit,
		USART_ParityEven_2StopBit,
		USART_ParityOdd_1StopBit,
		USART_ParityOdd_2StopBit,
	}USART_ControlFrame;

	/* Use this Only in Case of Sync Communication to Set Sampling Setting */
	typedef enum
	{
		USART_SampleOnFalling,
		USART_SampleOnRising,
	}USRT_ClockPolarity;

	typedef enum
	{
		USART_NoBlock,
		USART_Block,
	}USART_HandleMode;

	typedef enum
	{
		USART0_RxComp_CallBack,
		USART0_TxComp_CallBack,
		USART0_DataRegEmpty_CallBack,
	}USART_CallBacks;

	typedef struct
	{
		/******************** Please Refere to The Upper Enum to Set Req Setting **********************/
		USART_EnableMode				 EnableMode;
		USART_CommunicationType			 CommunicationType;
		USART_CommunicationTerminal      CommunicationTerminal;
		USART_InterruptSource			 InterruptSource;
		USART_DataFrame					 DataFrame;
		USART_ControlFrame			     ControlFrame;
		USRT_ClockPolarity				 ClockPlolarity;  /* Use only in Sync Mode */
		uint32_t 						 BaudRate;
		USART_ErrorTypes 				 USART_Error;     /* Errors wont be Cleared Automaticly */
	}USART_Config;


	extern USART_Config    USART0_ConfigStructure;


	void	USART_Init(void);

	void	USART_SendByte(uint16 Data,USART_HandleMode Mode);

	uint16	USART_RcvByte(USART_HandleMode Mode);

	void USART_SetInterruptCall(USART_CallBacks CallSource, void (*pf) (void));

#endif /* ATMEGA32A_USART_H_ */
