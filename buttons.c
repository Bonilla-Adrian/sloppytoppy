#include "buttons.h"
#include "notes.h"
#include "melody.h"
#include "buzzer.h"

void buttons_init(void) {
    P2DIR &= ~(S1 | S2 | S3 | S4);       // Set P2.0 to P2.3 as inputs
    P2REN |= (S1 | S2 | S3 | S4);        // Enable pull-up resistors for P2.0 to P2.3
    P2OUT |= (S1 | S2 | S3 | S4);        // Set pull-up resistors for P2.0 to P2.3

    P2IES |= (S1 | S2 | S3 | S4);        // Interrupt on high-to-low transition
    P2IFG &= ~(S1 | S2 | S3 | S4);       // Clear interrupt flags for P2.0 to P2.3
    P2IE |= (S1 | S2 | S3 | S4);         // Enable interrupts for P2.0 to P2.3
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    if(P2IFG & S1) // If interrupt source is S1
    {
        // Play the melody
        playMelody(melody, noteDurations, melodyLength);
        P2IFG &= ~S1; // Clear interrupt flag for P2.0
    }

    if(P2IFG & S2) // If interrupt source is S2
    {
        // Placeholder for S2 functionality
        // You can add some code here for S2 later
        P2IFG &= ~S2; // Clear interrupt flag for P2.1
    }

    if(P2IFG & S3) // If interrupt source is S3
    {
        // Placeholder for S3 functionality
        // You can add some code here for S3 later
        P2IFG &= ~S3; // Clear interrupt flag for P2.2
    }

    if(P2IFG & S4) // If interrupt source is S4
    {
        // Placeholder for S4 functionality
        // You can add some code here for S4 later
        P2IFG &= ~S4; // Clear interrupt flag for P2.3
    }

    // Enter low power mode
    __bis_SR_register(LPM4_bits);
}
