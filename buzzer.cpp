#include "buzzer.h"
#include "mbed.h"

DigitalOut buzzer_pin(PA_0);

void Buzzer_Init() {
    // DigitalOut handles pin setup
}

void Buzzer_Alarm(uint32_t duration_ms) {
    buzzer_pin = 1;
    ThisThread::sleep_for(chrono::milliseconds(duration_ms));
    buzzer_pin = 0;
}
