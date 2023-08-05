#include <msp430.h>
#include "buzzer.h"
#include "notes.h"

// Define the frequency for the system clock (SMCLK)
#define SMCLK_FREQ 1000000  // Assuming SMCLK is set to 1MHz

// Functions related to timer and buzzer initialization and control

void timerAUpmode()
{
    TA0CCR0 = 0;  // Initialize counter to 0
    TA0CCR1 = 0;  // Initialize duty cycle to 0% (off)
    TA0CTL |= TASSEL_2 + MC_1;  // Source: SMCLK, Mode: Up to CCR0
    TA0CCTL1 |= OUTMOD_7;  // Output mode: Reset on CCR1, set on CCR0
}

void buzzer_init() {
    // Set up Timer A to run in up mode
    timerAUpmode();
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;  // Set P2.6 as output
}

void playBuzzer(float frequency)
{
    int timerPeriod = SMCLK_FREQ / frequency;  // Calculate timer period for desired frequency
    TA0CCR0 = timerPeriod;
    TA0CCR1 = timerPeriod / 2;  // 50% duty cycle
    TA0CTL |= TASSEL_2 + MC_1;  // Source: SMCLK, Mode: Up to CCR0
    P1OUT |= (BIT0 | BIT1);  // Turn on LEDs on P1.0 and P1.1
}

void stopBuzzer()
{
    TA0CTL = MC_0;  // Stop the timer
    P2OUT &= ~BIT6;  // Turn off the buzzer
    P1OUT &= ~(BIT0 | BIT1);  // Turn off LEDs on P1.0 and P1.1
}

void delay_ms(int ms)
{
    while (ms--) 
    {
        __delay_cycles(SMCLK_FREQ / 1000);  // 1 ms delay
    }
}

void playMelody(float melody[], int durations[], int length) {
    for (int i = 0; i < length; i++) {
        if (melody[i] != NOTE_REST) {
            playBuzzer(melody[i]);
        } else {
            stopBuzzer();
        }
        delay_ms(1000 / durations[i]);
        stopBuzzer();
        delay_ms(250);  // Short delay between notes
    }
}
