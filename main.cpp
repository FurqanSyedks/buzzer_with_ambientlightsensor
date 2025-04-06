#include "mbed.h"
#include "buzzer.h"

AnalogIn lightSensor(PA_1); // Analog input from LDR voltage divider
float threshold = 0.5f;     // Adjust based on your environment

int main() {
    Buzzer_Init();

    while (true) {
        float lightLevel = lightSensor.read(); // 0.0 to 1.0
        printf("Light Level: %.2f\n", lightLevel);

        if (lightLevel > threshold) {
            // Food is LOW → more light → buzzer ON
            Buzzer_Alarm(500);
        }

        ThisThread::sleep_for(1s);
    }
}
