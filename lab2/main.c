#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 8000000

unsigned char code8[10] = {0b11000000,
							0b11111001,
							0b10100100,
							0b10110000,
							0b10011001,
							0b10010010,
							0b10000010,
							0b11111000,
							0b10000000,
							0b10010000,
							0b10010000,
							0b10000011,
							0b11000110,
							0b10100001,
							0b10000110,
							0b10001110};

int main()
{
	DDRC = 0;
	PORTC = 0xFF;
	DDRD = 0xFF;
	PORTD = 0xFF;
	DDRB = 0xFF;
	PORTB = 0;
	while(1)
	{
		unsigned char a = PINC;
		unsigned char k = 1;
		while(a != 0)
		{
			PORTD = code8[a - (a/16*16)];
			a /= 16;
			PORTB = k;
			_delay_ms(5);
			PORTB = 0;
			if(k == 1)
			{
				k <<= 4;
			} else
			{
				k <<= 1;
			}
		}
	}
	return 0;
}

