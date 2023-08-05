#include "melody.h"
#include "notes.h"

float melody[] = {
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_F4s, NOTE_F4s, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_C4s, NOTE_B4,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_D4, NOTE_E4, NOTE_C4s, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_D4, NOTE_REST,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_F4s, NOTE_F4s, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_A5, NOTE_C4s, NOTE_D4, NOTE_C4s, NOTE_B4, NOTE_REST,
    NOTE_A4, NOTE_B4, NOTE_D4, NOTE_B4, NOTE_D4, NOTE_E4, NOTE_C4s, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_D4
};

int noteDurations[] = {
    16, 16, 8, 16, 4, 8, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 4, 4, 4, 8,
    16, 16, 8, 16, 4, 8, 2,
    16, 16, 8, 16, 4, 8, 16, 16, 4, 8,
    16, 16, 8, 16, 4, 16, 16, 16, 4, 4, 4,
};

int melodyLength = sizeof(melody) / sizeof(melody[0]);
