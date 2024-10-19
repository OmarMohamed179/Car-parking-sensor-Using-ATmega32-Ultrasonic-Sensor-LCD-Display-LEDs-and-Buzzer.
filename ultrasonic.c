/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Omar Mohamed
 */

#include"ultrasonic.h"
#include "std_types.h"
#include"gpio.h"
#include"util/delay.h"
#include"icu.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;


void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{

		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */


		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount=0;


	}

}


void Ultrasonic_init(void)
{
	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void)
{
    Ultrasonic_Trigger();
    uint16 distance = (g_timeHigh / 117.6);  // Convert time to distance
    return distance;
}


