#ifndef BUTTONS_H_
#define BUTTONS_H_
#include <msp430.h>

extern volatile unsigned int playFlag; // Declare the playFlag variable for external access

#define S1 BIT0  // P2.0
#define S2 BIT1  // P2.1
#define S3 BIT2  // P2.2
#define S4 BIT3  // P2.3

// Function prototypes
void buttons_init(void);

#endif // BUTTONS_H_
