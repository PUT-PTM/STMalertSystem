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
	int x = 0;
	int i;

	while (1) {
		//Wysyłanie komunikatów w trakcie pracy
		uint8_t theByte;
		if (VCP_get_char(&theByte)) {
			send_byte(theByte);
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			for (i = 0; i < 1000000; i++)
				;
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);
			for (i = 0; i < 1000000; i++)
				;
		}
		//Uzbrajanie alaramu
		if (decision == 1) {
			//Status włączonego alarmu
			GPIO_SetBits(GPIOD, GPIO_Pin_14);

			if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)) {
				while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 1) //jezeli bit na PC7=1 -> pomarczowa dioda
				{
					//Wyślij komunikat do ESP
					if (x == 0) {
						send_string("AT+CIPSEND=0,1\r\n");
						for (i = 0; i < 1000000; i++)
							;
						send_string("1\r\n");
						x = 1;
					}
					GPIO_SetBits(GPIOD, GPIO_Pin_15);
					for (i = 0; i < 1000000; i++)
						;
					GPIO_ResetBits(GPIOD, GPIO_Pin_15);
					for (i = 0; i < 1000000; i++)
						;
					TIM_Cmd(TIM6, ENABLE);
				}

				while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6) == 1) //jezeli bit na PC7=1 -> niebieska dioda
				{
					if (x == 0) {
						send_string("AT+CIPSEND=0,1\r\n");
						for (i = 0; i < 1000000; i++)
							;
						send_string("1\r\n");
						x = 1;
					}
					GPIO_SetBits(GPIOD, GPIO_Pin_13);
					for (i = 0; i < 1000000; i++)
						;
					GPIO_ResetBits(GPIOD, GPIO_Pin_13);
					for (i = 0; i < 1000000; i++)
						;
					TIM_Cmd(TIM6, ENABLE);
				}
				TIM_Cmd(TIM6, DISABLE);
				x = 0;
			}
		}
		//Rozbrajanie alarmu
		if (decision == 0) {
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
		}
	}
}
