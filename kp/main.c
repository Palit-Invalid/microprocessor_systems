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

void ADC_Init()
{
    ADCSRA = 0b10000111;            /* Включаем АЦП. делитель 128  */
    ADMUX = 0b01000000;             /* Выбираем опорное напряжение и 0 канал */
}

int ADC_Read(uint8_t channel)
{
    int Ain, AinLow;
    
    ADMUX |= (channel & 0b00000111);    /* Выбор канала для чтения */
    ADCSRA |= (1 << ADSC);               /* Начало преобразования */
    while((ADCSRA & (1 << ADIF)) == 0);  /* Ждем окончания преобразования */
    
    _delay_us(10);
    AinLow = (int) ADCL;                 /* Читаем младший байт*/
    Ain = (int) ADCH * 256;              /* Читаем старший байт и соединяем в одно двух байтное число */
    Ain += AinLow;                
    return Ain;                         /* Возвращаем цифровой код */
}

int main()
{
	DDRD = 0xFF;
	DDRB = 0xFF;

    ADC_Init();

    int num;
	while(1)
	{
        srand(ADC_Read(0));
        num = rand() % 100;
		
        PORTB = 0b00000001;
        PORTD = code8[num/10];
        _delay_ms(1000);
        PORTB = 0b00000100;
        PORTD = code8[num % 10];
        _delay_ms(1000);

	}
	return 0;
}
