/*
 * Motor_Driver.c
 *
 * Created: 12/9/2021 4:38:33 AM
 *  Author: evram
 */ 

#include "Motor_Driver.h"
#include <util/delay.h>

void motor_init()
{
	
	Dio_ChannelDirectionSet(MOTORS_DIR,DIO_PIN0 , DIO_OUTPUT);
	Dio_ChannelDirectionSet(MOTORS_DIR,DIO_PIN1 , DIO_OUTPUT);
	Dio_ChannelDirectionSet(MOTORS_DIR,DIO_PIN2 , DIO_OUTPUT);
	Dio_ChannelDirectionSet(MOTORS_DIR,DIO_PIN3 , DIO_OUTPUT);
	
}

void motor_forward()
{
	
	Dio_ChannelWrite(MOTORS_OUT,IN1,DIO_HIGH);
	Dio_ChannelWrite(MOTORS_OUT,IN4,DIO_HIGH);

}

void motor_brake()
{
	
	Dio_ChannelWrite(MOTORS_OUT,IN1,DIO_LOW);
	Dio_ChannelWrite(MOTORS_OUT,IN4,DIO_LOW);
	
	//Dio_ChannelWrite(MOTORS_OUT,IN2,DIO_HIGH);
	//Dio_ChannelWrite(MOTORS_OUT,IN3,DIO_HIGH);
	
	//_delay_ms(500);
	Dio_ChannelWrite(MOTORS_OUT,IN2,DIO_LOW);
	Dio_ChannelWrite(MOTORS_OUT,IN3,DIO_LOW);

}

void motor_right()
{
	
	Dio_ChannelWrite(MOTORS_OUT,IN2,DIO_HIGH);
	Dio_ChannelWrite(MOTORS_OUT,IN4,DIO_HIGH);
	
	_delay_ms(2000);

	Dio_ChannelWrite( MOTORS_OUT,IN2,DIO_LOW);
	Dio_ChannelWrite( MOTORS_OUT,IN4,DIO_LOW);
}

void motor_left()
{
	
	Dio_ChannelWrite(MOTORS_OUT,IN1,DIO_HIGH);
	Dio_ChannelWrite(MOTORS_OUT,IN3,DIO_HIGH);
	
	_delay_ms(2000);

	Dio_ChannelWrite( MOTORS_OUT,IN1,DIO_LOW);
	Dio_ChannelWrite( MOTORS_OUT,IN3,DIO_LOW);
}