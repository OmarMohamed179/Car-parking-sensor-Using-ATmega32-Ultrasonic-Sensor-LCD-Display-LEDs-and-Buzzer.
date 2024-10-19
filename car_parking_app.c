/*
 * car_parking_app.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Omar Mohamed
 */
#include"std_types.h"
#include"common_macros.h"
#include"gpio.h"
#include"lcd.h"
#include"LED.h"
#include"buzzer.h"
#include"icu.h"
#include"ultrasonic.h"
#include"avr/io.h"
#include"util/delay.h"


int main()
{
	uint16 g_distance;
	SREG |=(1<<7);
	/*Initialize modules*/
	LEDS_init();
	Buzzer_init();
	LCD_init();
	Ultrasonic_init();

	LCD_displayStringRowColumn(0, 1, "Distance=   cm");


	while(1)
	{
		 g_distance=Ultrasonic_readDistance()+1;
		 LCD_moveCursor(0,10);
		 LCD_intgerToString(g_distance);
		 if (g_distance < 10)
		 {
		 			LCD_displayStringRowColumn(0, 11, " ");
		 }



		if((g_distance>=0) &&(g_distance <= 5))
		{
			LCD_displayStringRowColumn(1, 7, "STOP");
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			Buzzer_on();
			_delay_ms(1000);
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();
			_delay_ms(1000);



		}
		else if((g_distance>=6) && (g_distance <= 10))
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
			Buzzer_off();
			LCD_displayStringRowColumn(1, 7, "    ");

		}
		else if((g_distance>=11) && (g_distance <= 15))
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();
			LCD_displayStringRowColumn(1, 7, "    ");

		}
		else if((g_distance>=16) && (g_distance <= 20))
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
			Buzzer_off();
			LCD_displayStringRowColumn(1, 7, "    ");


		}
		else
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(GREEN_LED);
			Buzzer_off();
			LCD_displayStringRowColumn(1, 7, "    ");

		}
	}
}

