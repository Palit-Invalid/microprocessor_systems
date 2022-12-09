#include<avr/io.h>
#include<util/delay.h>

#include<stdlib.h>
#include<time.h>

uint8_t code8[] = { 0b11000000,
                    0b11111001,
                    0b10100100,
                    0b10110000,
                    0b10011001,
                    0b10010010,
                    0b10000010,
                    0b11111000,
                    0b10000000,
                    0b10010000 };

void test_numbers(uint8_t array[])
{
    for(int i = 0; i < sizeof(code8); i++)
    {
        PORTD = code8[i];
        _delay_ms(2000);
    }
}

int main()
{
    // Setup ports: 0 - input, FF - output
	// DDR{A,B,C,D}

	DDRD = 0xFF;
	DDRB = 0xFF;

	// Random init
	// srand(time(NULL));
	int num = 61;

    

	while(1)
	{
        // test_numbers(code8);
		
        PORTB = 0b00000001;
        PORTD = code8[num/10];
        _delay_ms(100);
        PORTB = 0b00000100;
        PORTD = code8[num % 10];
        _delay_ms(100);

	}
	return 0;
}
