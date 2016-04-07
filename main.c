/*
To do:(wtorek)
-oddzielnie biblioteki na inity
-obsluga czujników z timerami
-glosnik
-diody na drugiej plytce
-stabilizacja
 */

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_dac.h"

/*opoznienie*/
void delay(int a)
{
int i=0;
for(i;i<a;i++)
{}
}

int main(void)
{
	SystemInit();
	/*RCC*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE); //DAC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //ADC

	/*GPIO diody*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/*GPIO czujniki*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*DAC g³osnik+diody na drugiej plytce*/
	DAC_InitTypeDef DAC_InitStructure;
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_1, ENABLE);

    while(1)
    {
    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)==1)//jezeli bit na PC7=1 -> pomarañczowa dioda
    	{
    		GPIO_SetBits(GPIOD, GPIO_Pin_15);
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    	}

    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)==1) //jezeli bit na PC7=1 -> niebieska dioda
    	{
    	    GPIO_SetBits(GPIOD, GPIO_Pin_13);
    	    GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    	}
    }
}


