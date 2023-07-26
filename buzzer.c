#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

// Add the definitions for the song notes and their corresponding frequencies
#define NOTE_C4  7645 // Frequency for note C4
#define NOTE_D4  6811 // Frequency for note D4

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void play_never_gonna_give_you_up()
{
    // TODO: Implement the logic to play the "Never Gonna Give You Up" song
    // You can use the buzzer_set_period() function to play each note
}

