#include <msp430.h>
#include "notes.h"
#include "melody.h"
#include "buzzer.h"
#include "buttons.h"

// Main function
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

    buzzer_init();  // Initialize the buzzer
    buttons_init(); // Initialize the buttons

    P1DIR |= (BIT0 | BIT1);  // Set P1.0 and P1.1 as outputs
    P1OUT &= ~(BIT0 | BIT1);  // Ensure LEDs are off to start

    // Enable global interrupts
    __bis_SR_register(GIE);

    playMelody(melody, noteDurations, melodyLength);

    while(1)
    {
        playMelody(melody, noteDurations, melodyLength);
        // Enter low power mode
        __bis_SR_register(LPM4_bits);
    }

    return 0;
}