/*
 * TESLA.c
 *
 * Created: 12/10/2021 10:09:39 PM
 * Author : evram
 */ 

#include <avr/io.h>
#include "ultrasonic.h"
#include "Servo.h"
#include "Motor_Driver.h"

int main(void)
{
	Servo_Init();
	ultrasonic_init();
	motor_init();
	lcd_init();
	sei();
	lcd_write_word("Distance is ");
   
	   
    while (1) 
    {
		ultra_triger();
		_delay_ms(15);
		motor_forward();
    }
}







 /*uint32 dis =0;
    uint32 left_dis =0;
    uint32 right_dis =0;*/
/*servo_rotate90();

		if (distance <= 10)
		{
			motor_brake();
			
			servo_rotate0();
			right_dis = distance;
			servo_rotate180();
			left_dis =distance;
			
			if (right_dis < left_dis )
			{
				motor_left();
			} else
			{
				motor_right();
			}
			
			
		} else 
		{
			motor_forward();
		}
		
		motor_forward();*/
		