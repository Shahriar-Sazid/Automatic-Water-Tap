/*
 * ATmega32 Stepper Motor Control
 * http://www.electronicwings.com
 *
 */ 


#define F_CPU 125000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */
#define DELAY 10

int main(void)
{
	int on = -1;
	int period;
	DDRD = 0x0f;		/* Make PORTD lower pins as output */
	period = 10;
	DDRA = 0x00;
	DDRC = 0xff;

	while (1)
	{
		int check = PINA>>2;
		check = check & 0x0001;
		if(check==0){
			if(on == -1){
				PORTC = 0x01;
				for(int i = 0; i<140; i++){
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x0c;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
				}
				on = 1;	
			}
		}
		else {
			if(on == 1){
				check = PINA>>2;
				check = check & 0x0001;
				if(check!=0){
					PORTC = 0x00;
					for(int i = 0; i<140; i++){
						PORTD = 0x08;
						_delay_ms(period);
						PORTD = 0x0c;
						_delay_ms(period);
						PORTD = 0x04;
						_delay_ms(period);
						PORTD = 0x06;
						_delay_ms(period);
						PORTD = 0x02;
						_delay_ms(period);
						PORTD = 0x03;
						_delay_ms(period);
						PORTD = 0x01;
						_delay_ms(period);
						PORTD = 0x09;
					}
					on = -1;
				}
			}
		}	
	}
	/* Rotate Stepper Motor clockwise with Half step sequence */
			
}