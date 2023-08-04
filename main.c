#include <msp430.h>
#include "button.h"
#include "buzzer.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    button_init(); // Initialize the button
    buzzer_init(); // Initialize the buzzer

    // Main loop
    while (1)
    {
        // Check if the button is pressed
        if (button_is_pressed())
        {
            play_melody(); // Play the melody if the button is pressed
        }
    }

    return 0;
}
