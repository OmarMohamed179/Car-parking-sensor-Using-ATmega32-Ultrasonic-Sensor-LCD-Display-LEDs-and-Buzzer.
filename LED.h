/*
 * LED.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Omar Mohamed
 */

#ifndef LED_H_
#define LED_H_
#include<avr/io.h>
#include"gpio.h"

#define LEDS_PORT_ID PORTC_ID
typedef enum {
    RED_LED=PIN0_ID,
    GREEN_LED=PIN1_ID,
    BLUE_LED=PIN2_ID
} LED_ID;
#define POSITIVE_LOGIC

#ifdef POSITIVE_LOGIC

#define LED_ON   LOGIC_HIGH
#define LED_OFF  LOGIC_LOW

#else

#define LED_ON   LOGIC_LOW
#define LED_OFF  LOGIC_HIGH

#endif
void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);



#endif /* LED_H_ */
