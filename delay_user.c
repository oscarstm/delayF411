/*
 * delay_user.c
 *
 *  Created on: Nov 24, 2025
 *      Author: oscar
 */

#include "delay_user.h"

void ms_delay(uint16_t ms) {
	if (ms == 0) {
		return;
	}
	// enable timer 9
	RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;

	TIM9->CR1 &= ~TIM_CR1_CEN;
	TIM9->SR = 0;
	TIM9->CNT = 0;
	TIM9->PSC = 100000 - 1;
	TIM9->ARR = ms - 1;
	TIM9->CR1 |= TIM_CR1_CEN;

	while ((TIM9->SR & TIM_SR_UIF) == 0) {
		//
	}
}
