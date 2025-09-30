#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    uint8_t counter = 0;
    DDRD |= (1 << PD5) | (1 << PD4) | (1 << PD3);
    PORTD |= (1 << PD6);
    while (1)
    {
        if (counter == 4)
        {
            PORTD &= ~((1 << PD5) | (1 << PD4) | (1 << PD3));
            counter = 0;
        }

        if (!(PIND & (1 << PD6)))
        {
            counter++;
            _delay_ms(200);
            while (!(PIND & (1 << PD6)));
        }

        switch (counter)
        {
        case 1:
            PORTD |= (1 << PD5);
            break;
        case 2:
            PORTD |= (1 << PD4);
            break;
        case 3:
            PORTD |= (1 << PD3);
            break;
        }
    }
}

