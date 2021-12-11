#include "ultrasonic.h"
#include "Servo.h"
#include "Motor_Driver.h"


uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];
uint32_t left_dis;
uint32_t right_dis;

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();
  return;
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultra_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect)
{
  if(sensor_working==1)
  {
    if(rising_edge==0)
	{
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else 
    {
    distance=(timer_counter*256+TCNT0)/931;
    lcd_goto_xy(1,0);
  	itoa(distance,distance_str,10);
  	strcat(distance_str, " cm ");
  	lcd_write_word(distance_str);
  	_delay_ms(40);
	 servo_rotate90();
    timer_counter=0;
    rising_edge=0;
	
	
	if (distance <= 10)
	{
		motor_brake();
	
	
	servo_rotate90();
	//_delay_ms(500);
	
	servo_rotate0();
	_delay_ms(500);
	left_dis = distance;
	_delay_ms(500);

	servo_rotate180();
	_delay_ms(500);
	right_dis = distance;
	_delay_ms(500);
	
	servo_rotate90();
	
	if (right_dis < left_dis )
	{
		motor_left();
		//_delay_ms(500);
	    motor_forward();

	} else
	{
		motor_right();
		//_delay_ms(500);
		motor_forward();
	   
	}
	
	servo_rotate90();
	} else {
		motor_forward();
	}
	
    }
  }
}

ISR(TIMER0_OVF_vect)
{
    timer_counter++;
    if(timer_counter >730)
	{
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}

