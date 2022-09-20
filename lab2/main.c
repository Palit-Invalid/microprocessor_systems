#include<avr/io.h>
#include<util/delay.h>

unsigned char code8[] = { 0b11000000,    // 0
                          0b11111001,    // 1
                          0b10100100,    // 2
                          0b10110000,    // 3
                          0b10011001,    // 4
                          0b10010010,    // 5
                          0b10000010,    // 6
                          0b11111000,    // 7
                          0b10000000,    // 8
                          0b10010000,    // 9
                          0b10010000,    // A
                          0b10000011,    // b
                          0b11000110,    // C
                          0b10100001,    // d
                          0b10000110,    // E
                          0b10001110 };  // F

int main()
{
	// Setup ports: 0 - input, FF - output
	// DDR{A,B,C,D}
	 
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
				k <<= 4; // Variant 2
			else
				k <<= 1;
		}
	}
	return 0;
}

