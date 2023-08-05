#include <msp430.h>
#include "notes.h"
#include "melody.h"
#include "buzzer.h"

// Main function
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

    buzzer_init();  // Initialize the buzzer

    P1DIR |= (BIT0 | BIT1);  // Set P1.0 and P1.1 as outputs
    P1OUT &= ~(BIT0 | BIT1);  // Ensure LEDs are off to start

    // Play the melody
    playMelody(melody, noteDurations, melodyLength);

    return 0;
}