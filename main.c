#include <msp430.h>
#include "notes.h"
#include "melody.h"
#include "buzzer.h"
#include "buttons.h"

volatile unsigned int playFlag = 0;  // Add a flag for melody playback

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

    while(1)
    {
        if(playFlag) // Check if the playFlag is set
        {
            playMelody(melody, noteDurations, melodyLength);
            playFlag = 0; // Reset the flag
        }
        // Enter low power mode
        __bis_SR_register(LPM4_bits);
    }

    return 0;
}
