#include <msp430.h>
#include "buzzer.h"

#define NOTE_C 261
#define NOTE_D 294
#define NOTE_E 329
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 466

float melody[] = {
    NOTE_E, NOTE_D, NOTE_E, NOTE_F, NOTE_G
    // Define the rest of the melody sequence here
};

int noteDurations[] = {
    4, 4, 4, 4, 4
    // Define the rest of the note durations here
};

void buzzer_init() {
    P1SEL |= BIT2; // Select TA0.1 for P1.2
    P1DIR |= BIT2; // Set P1.2 to output
    TACTL |= TASSEL_2 + MC_1; // SMCLK, up mode
    TACCR0 = 1000-1; // PWM period
    TACCR1 = 0; // PWM duty cycle, initially off
    TACTL |= TAIE; // Enable Timer A interrupt
}

void play_melody() {
    int melodyLength = sizeof(melody) / sizeof(melody[0]);
    for (int i = 0; i < melodyLength; i++) {
        float duration = 1000 / noteDurations[i];
        float note = melody[i];
        TACCR1 = (int)(note / (1000000 / 1000)); // Set the PWM duty cycle for the note
        __delay_cycles(duration * 1000000); // Wait for the duration of the note
        TACCR1 = 0; // Turn off the buzzer between notes
        __delay_cycles(duration * 250000); // Short pause between notes
    }
    TACCR1 = 0; // Turn off the buzzer at the end of the melody
}
