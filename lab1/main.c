#include<avr/io.h>
#include<util/delay.h>

int main()
{
	DDRD = 0xFF;
	DDRC = 0;
	PORTC = 0xFF;
	while(1)
	{
		if(PINC & 0b10101010)
		{
			PORTD = 0b01010101;
		}
		if(PINC == 0b00000000)
		{
			PORTD = 0b00000000;
		}
	}
	return 0;
}
