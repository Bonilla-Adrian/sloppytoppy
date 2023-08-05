#include <msp430.h>

// Define the frequencies for musical notes
#define NOTE_A  440.00
#define NOTE_A5 880.00
#define NOTE_B  493.88
#define NOTE_Cs 554.37
#define NOTE_D  587.33
#define NOTE_E  659.26
#define NOTE_Fs 739.99
#define NOTE_REST 0.00 // Represents a rest or pause

// Define the frequency for the system clock (SMCLK)
#define SMCLK_FREQ 1000000  // Assuming SMCLK is set to 1MHz

// Define the melody sequence
float melody[] = {
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_Fs, NOTE_Fs, NOTE_E,
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_E, NOTE_E, NOTE_D, NOTE_Cs, NOTE_B,
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_D, NOTE_E, NOTE_Cs, NOTE_A, NOTE_A, NOTE_E, NOTE_D, NOTE_REST,
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_Fs, NOTE_Fs, NOTE_E,
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_A5, NOTE_Cs, NOTE_D, NOTE_Cs, NOTE_B, NOTE_REST,
    NOTE_A, NOTE_B, NOTE_D, NOTE_B, NOTE_D, NOTE_E, NOTE_Cs, NOTE_A, NOTE_A, NOTE_E, NOTE_D
};

// Define the duration for each note in the melody
int noteDurations[] = {
    16, 16, 8, 16, 4, 8, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 4, 4, 2, 8,
    16, 16, 8, 16, 4, 8, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 4, 8,
    16, 16, 8, 16, 4, 8, 16, 16, 4, 4, 4,
};

// Set up Timer A to run in up mode
void timerAUpmode()
{
    TA0CCR0 = 0;  // Initialize counter to 0
    TA0CCR1 = 0;  // Initialize duty cycle to 0% (off)
    TA0CTL |= TASSEL_2 + MC_1;  // Source: SMCLK, Mode: Up to CCR0
    TA0CCTL1 |= OUTMOD_7;  // Output mode: Reset on CCR1, set on CCR0
}

// Initialize buzzer on P2.6
void buzzer_init()
{
    timerAUpmode();  // Set up timer for PWM
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;  // Set P2.6 as output
}

// Play a note on the buzzer
void playBuzzer(float frequency)
{
    int timerPeriod = SMCLK_FREQ / frequency;  // Calculate timer period for desired frequency
    TA0CCR0 = timerPeriod;
    TA0CCR1 = timerPeriod / 2;  // 50% duty cycle
    TA0CTL |= TASSEL_2 + MC_1;  // Source: SMCLK, Mode: Up to CCR0
    P1OUT |= (BIT0 | BIT1);  // Turn on LEDs on P1.0 and P1.1
}

// Stop the buzzer
void stopBuzzer()
{
    TA0CTL = MC_0;  // Stop the timer
    P2OUT &= ~BIT6;  // Turn off the buzzer
    P1OUT &= ~(BIT0 | BIT1);  // Turn off LEDs on P1.0 and P1.1
}

// Delay for a specified number of milliseconds
void delay_ms(int ms)
{
    while (ms--) 
    {
        __delay_cycles(SMCLK_FREQ / 1000);  // 1 ms delay
    }
}

// Main function
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

    buzzer_init();  // Initialize the buzzer

    P1DIR |= (BIT0 | BIT1);  // Set P1.0 and P1.1 as outputs
    P1OUT &= ~(BIT0 | BIT1);  // Ensure LEDs are off to start

    // Play the melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        if (melody[i] != NOTE_REST) {
            playBuzzer(melody[i]);
        } else {
            stopBuzzer();
        }
        delay_ms(1000 / noteDurations[i]);
        stopBuzzer();
        delay_ms(250);  // Short delay between notes
    }

    return 0;
}