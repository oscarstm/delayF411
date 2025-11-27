#include "stm32f4xx.h"
#include "clk_user.h"
#include "delay_user.h"
#include "gpio_user.h"

int main(void) {
	clk_user_init();
	gpio_init();

	while (1) {
		GPIOC->BSRR |= GPIO_BSRR_BS13;
		ms_delay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BR13;
		ms_delay(1000);
	}

}

