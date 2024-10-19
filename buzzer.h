/*
 * buzzer.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Omar Mohamed
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "gpio.h"
#define BUZZER_PORT_ID PORTC_ID
#define BUZZER_PIN_ID  PIN5_ID  // Define the pin connected to the buzzer

// Function to initialize the buzzer
void Buzzer_init(void);

// Function to turn on the buzzer
void Buzzer_on(void);

// Function to turn off the buzzer
void Buzzer_off(void);



#endif /* BUZZER_H_ */
