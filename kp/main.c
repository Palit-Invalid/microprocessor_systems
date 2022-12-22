#include<avr/io.h>
#include<avr/eeprom.h>
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
    DDRA = 0;

	// Random init
	// srand(100);
	// int num = rand();

    uint16_t randinit; 
    srand(eeprom_read_word(&randinit));
    eeprom_write_word(&randinit, rand());
    int num = rand();

	while(1)
	{
        // test_numbers(code8);
		
        PORTB = 0b00000001;
        PORTD = code8[num/10];
        _delay_ms(1000);
        PORTB = 0b00000100;
        PORTD = code8[num % 10];
        _delay_ms(1000);

	}
	return 0;
}
