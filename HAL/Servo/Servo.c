/*
 * Servo.c
 *
 * Created: 12/10/2021 9:34:29 PM
 *  Author: evram
 */ 


#include <avr/io.h>
#include <util/delay.h>

void Servo_Init()
{
	DDRD = 0x80; //Makes RD7 output pin
	PORTD = 0x00;
	
}

void servo_rotate0()
{
	PORTD = 0x80;
	_delay_us(388);
	PORTD = 0x00;
}
void servo_rotate90()
{
	PORTD = 0x80;
	_delay_us(1264);
	PORTD = 0x00;
}
void servo_rotate180()
{
	PORTD = 0x80;
	_delay_us(2140);
	PORTD = 0x00;
}