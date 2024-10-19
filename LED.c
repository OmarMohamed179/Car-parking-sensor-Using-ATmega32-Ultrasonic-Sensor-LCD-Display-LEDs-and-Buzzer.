/*
 * LED.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Omar Mohamed
 */

#include "LED.h"
#include"gpio.h"
#include "std_types.h"
void LEDS_init(void)
{
	GPIO_setupPinDirection(PORTC_ID,RED_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,GREEN_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID,BLUE_LED,PIN_OUTPUT);
	GPIO_writePin(PORTC_ID,RED_LED,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,GREEN_LED,LOGIC_LOW);
	GPIO_writePin(PORTC_ID,BLUE_LED,LOGIC_LOW);

    // Set PB5, PB6, PB7 as output

	/*
    DDRB |= (1 << PB5) | (1 << PB6) | (1 << PB7);
    // Turn off all LEDs
    PORTB &= ~(1 << PB5);
    PORTB &= ~(1 << PB6);
    PORTB &= ~(1 << PB7);
    */
}

void LED_on(LED_ID id) {
    switch (id) {
        case RED_LED:
        	GPIO_writePin(PORTC_ID,RED_LED,LOGIC_HIGH);
        break;
        case GREEN_LED:
        	GPIO_writePin(PORTC_ID,GREEN_LED,LOGIC_HIGH);
        break;
        case BLUE_LED:
        	GPIO_writePin(PORTC_ID,BLUE_LED,LOGIC_HIGH);
        	break;
    }
}

void LED_off(LED_ID id) {
    switch (id) {
        case RED_LED:
        	GPIO_writePin(PORTC_ID,RED_LED,LOGIC_LOW);
        	break;
        case GREEN_LED:
        	GPIO_writePin(PORTC_ID,GREEN_LED,LOGIC_LOW);
        	break;
        case BLUE_LED:
        	GPIO_writePin(PORTC_ID,BLUE_LED,LOGIC_LOW);
        	break;
    }
}

