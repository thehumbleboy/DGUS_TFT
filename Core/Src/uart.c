/*
 * uart.c
 *
 *  Created on: Oct 12, 2024
 *      Author: nj105
 */

#include "uart.h"

void UART2_GPIO_Init(){
	//Clock enable for GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	//GPIO Config
    // Configure PD5 as USART2_TX and PD6 as USART2_RX
    GPIOD->MODER &= ~(GPIO_MODER_MODER5 | GPIO_MODER_MODER6);  // Clear mode bits
    GPIOD->MODER |= (GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1);  // Set Alternate function mode (10)

    GPIOD->OTYPER &= ~(GPIO_OTYPER_OT5 | GPIO_OTYPER_OT6);  // Push-pull (0)

    GPIOD->OSPEEDR |= (GPIO_OSPEEDR_OSPEED5 | GPIO_OSPEEDR_OSPEED6);  // High speed (11)

    GPIOD->PUPDR &= ~(GPIO_PUPDR_PUPDR5 | GPIO_PUPDR_PUPDR6);  // No pull-up, no pull-down (00)

    // Set alternate function AF7 (USART2) for PD5 and PD6
    GPIOD->AFR[0] |= (7 << GPIO_AFRL_AFSEL5_Pos ) | (7 << GPIO_AFRL_AFSEL6_Pos);  // AF7 for both pins

}

void UART2_Init(){
	//Clock Enable for UART
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//UART Init

}
