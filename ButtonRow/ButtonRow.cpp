#include <Arduino.h>
#include <ButtonRow.h>

ButtonRow::ButtonRow(int analog_pin, int analog_button_values[], int analog_button_values_length, int threshold = 2, int repeat_click_timeout = 500) {
    _analog_button_values_length = analog_button_values_length;
    for (int i = 0; i < _analog_button_valuesLength; i++) {
        _analog_button_values[i] = analog_button_values[i];
    }
    _analog_pin = analog_pin;
    _threshold = threshold;
    _sensor_value = 0;
    _last_button_pressed = -1;
    _last_button_pressed_time = 0;
    _repeat_click_timeout = repeat_click_timeout;
}

int ButtonRow::getPushedButton() {
    _sensor_value = analogRead(_analog_pin);
    for (int i = 0; i < _analog_button_valuesLength; i++) {
        if (_sensor_value < _analog_button_values[i] + _threshold && _sensor_value > _analog_button_values[i] - _threshold) {
            if (_last_button_pressed != i || millis() - _last_button_pressed_time > _repeat_click_timeout) {
                _last_button_pressed = i;
                _last_button_pressed_time = millis();
                return i;
            }
            break;
        }
    }
    return -1;
}
