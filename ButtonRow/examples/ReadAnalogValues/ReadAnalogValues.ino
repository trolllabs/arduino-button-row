#include <Arduino.h>
#include <Wire.h>
#include <ButtonRow.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("Analog Value: ");
    Serial.println(analogRead(A0));
    delay(100);
}
