#include <Arduino.h>
#include <Wire.h>
#include <ButtonRow.h>

int button_values[] = {879, 181, 321, 985, 1024};
int size = sizeof(button_values) / sizeof(button_values[0]);
int threshold = 5;
int repeat_click_timeout = 500;
int analogIn = A0;
ButtonRow buttonRow(analogIn, button_values, size, threshold, repeat_click_timeout);

void setup() {
    Serial.begin(9600);

    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
}

void blink(int pin, int times, int d) {
    for (int j = 0; j < times; j++) {
        digitalWrite(pin, LOW);
        delay(d);
        digitalWrite(pin, HIGH);
        delay(d);
    }
    digitalWrite(pin, LOW);
}


void loop() {
    Serial.print("Button pressed: ");
    Serial.println(buttonRow.getPushedButton());
    Serial.print("Analog Value");
    Serial.println(analogRead(A0));

    switch (buttonRow.getPushedButton()) {
        case 0:
            blink(D6, 5, 100);
            Serial.println("one");
            break;
        case 1:
            blink(D6, 5, 300);
            Serial.println("two");
            break;
        case 2:
            blink(D5, 5, 500);
            Serial.println("three");
            break;
        case 3:
            blink(D5, 5, 400);
            Serial.println("four");
            break;
        case 4:
            blink(D5, 5, 500);
            Serial.println("five");
            break;
    }
    delay(100);
}
