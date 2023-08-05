#ifndef BUZZER_H
#define BUZZER_H

void buzzer_init();
void timerAUpmode();
void playBuzzer(float frequency);
void stopBuzzer();
void playMelody(float melody[], int durations[], int length);
void delay_ms(int ms);

#endif // BUZZER_H