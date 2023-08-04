#include <msp430.h>
#include "button.h"

#define BUTTON BIT3 // Assuming S1 is connected to P1.3

void button_init(void)
{
    P1DIR &= ~BUTTON; // Set P1.3 as input
    P1REN |= BUTTON; // Enable pull-up resistor
    P1OUT |= BUTTON; // Pull-up
}

int button_is_pressed(void)
{
    return !(P1IN & BUTTON); // Return 1 if button is pressed
}
