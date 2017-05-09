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
}

void loop() {
    Serial.print(buttonRow.getPushedButton());
    Serial.print("\n");
    delay(1000);
}