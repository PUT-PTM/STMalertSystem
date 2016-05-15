#define HSE_VALUE ((uint32_t)8000000) /* STM */
#include <VCP.h>
#include <init.h>
#include <time.h>

int main(void) {
	int lightsOn1 = 0, lightsOn2 = 0;
	SystemInit();
	SystemCoreClockUpdate();
	init_VCP();
	rcc();
	gpio();
	tim();
	usart();
	NVIC_usart();
	USART2_IRQHandler();
	MY_DAC_init();
	MY_DAC_initTimerForUpdating();
	MY_DMA_initM2P();
	int x=0;
	int i;



	while (1) {
		if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)) {
			while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 1) //jezeli bit na PC7=1 -> pomarczowa dioda
			{
				if (x==0)
				{
					send_string("Alarm \r\n");
					 x=1;
				}
				GPIO_SetBits(GPIOD, GPIO_Pin_15);
				for (i=0;i<1000000;i++);
				GPIO_ResetBits(GPIOD, GPIO_Pin_15);
				for (i=0;i<1000000;i++);
				TIM_Cmd(TIM6, ENABLE);
			}

			while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6) == 1) //jezeli bit na PC7=1 -> niebieska dioda
			{
				if (x==0)
				{
					send_string("Alarm \r\n");
					 x=1;
				}
				GPIO_SetBits(GPIOD, GPIO_Pin_13);
				for (i=0;i<1000000;i++);
				GPIO_ResetBits(GPIOD, GPIO_Pin_13);
				for (i=0;i<1000000;i++);
				TIM_Cmd(TIM6, ENABLE);
			}
			TIM_Cmd(TIM6, DISABLE);
			x=0;
		}
	}
}
