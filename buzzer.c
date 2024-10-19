/*
 * buzzer.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Omar Mohamed
 */

#include "common_macros.h"

#include "buzzer.h"
#include "gpio.h"
#include"std_types.h"

void Buzzer_init(void) {
    // Set the buzzer pin as output
    GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);

    // Turn off the buzzer at initialization
    Buzzer_off();
}

void Buzzer_on(void) {
    // Set the buzzer pin to high (turn buzzer ON)
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

void Buzzer_off(void) {
    // Set the buzzer pin to low (turn buzzer OFF)
   GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID, LOGIC_LOW);
}
