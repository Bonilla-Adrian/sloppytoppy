// Example code snippet to play the main melody of "Never Gonna Give You Up"
#include <msp430.h>
#include <edu_boosterpack.h>

// Function to play a single tone
void playTone(int frequency, int duration) {
    int period = 1000000 / frequency; // Calculate the period in microseconds
    int halfPeriod = period / 2; // Calculate half the period for toggling the output

    int i;
    for (i = 0; i < duration * 1000 / period; i++) {
        // Toggle the buzzer GPIO pin to generate the tone
        eduBoosterPack_toggleBuzzer();
        __delay_cycles(halfPeriod);
    }
}

int main(void) {
    // Initialize the system and button S1 pin
    WDTCTL = WDTPW + WDTHOLD;       // Stop WDT
    eduBoosterPack_init();          // Initialize EduKit BoosterPack
    eduBoosterPack_configureButtonS1AsInput(); // Configure button S1 as input

    // Define the frequencies for the notes in "Never Gonna Give You Up"
    int melody[] = {
        659, 659, 659, 523, 587, 659, 587, 523, 494, 523, 440, 494
    };
    
    int duration = 500; // Duration of each note in milliseconds

    while (1) {
        // Check if button S1 is pressed
        if (eduBoosterPack_isButtonS1Pressed()) {
            // Button S1 is pressed, play the melody of "Never Gonna Give You Up"
            int i;
            for (i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
                playTone(melody[i], duration);
                __delay_cycles(1000000); // Delay between notes
            }
        }
    }
}
