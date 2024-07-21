#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


//Datasheet 102
#define PULSE_MIN	12U
#define PULSE_MAX	24U
#define PULSE_MID	18U

#define TOP_VALUE 24//50 HZ 39999



int main(void)
{

	
	//TIMSK1 |= (1 << TOIE1) | (1 << OCIE1A);
	OCR1C = TOP_VALUE;
	TCCR1 |= (1 << COM1A1) | (0 << COM1A0) | (1 << CS13) | (1 << CS12) | (0 << CS11) | (1 << CS10) | (1 << CTC1);  // CS13, CS12, CS11, and CS10 are set to (1,1,0,1), which set the prescaler to 4096
	
	DDRB |= (1 << PB1);

	OCR1A = PULSE_MIN;
	//PORTD &= ~(1 << PD6); // LED used for debugging
	
	/* Replace with your application code */
	while (1)
	{
// 		for (uint16_t i = PULSE_MIN; i < PULSE_MAX; i = i + 20)
// 		{
// 			//PORTD |= (1 << PD6);
// 			OCR1A = i;
// 			_delay_ms(10);
// 			
// 			
// 		}
// 		
// 		for (uint16_t i = PULSE_MAX; i > PULSE_MIN; i = i - 20)
// 		{
// 			//PORTD &= ~(1 << PD6);
// 			OCR1A = i;
// 			_delay_ms(10);
// 			
// 		}
// 		
		OCR1A = PULSE_MIN;
		_delay_ms(500);
		OCR1A = PULSE_MID;
		_delay_ms(500);
		OCR1A = PULSE_MAX;
		_delay_ms(500);
		OCR1A = PULSE_MID;
		_delay_ms(500);
	}
}

