#ifndef ButtonRow_h
#define ButtonRow_h


class ButtonRow {
public:
    ButtonRow(int analog_pin, int analog_button_values[], int analog_button_values_length, int threshold, int repeat_click_timeout);

    int getPushedButton();

private:
    int _sensor_value;
    int _threshold;
    int _analog_pin;
    int _analog_button_values[16];
    int _analog_button_values_length;
    int _last_button_pressed = -1;
    int _repeat_click_timeout;
    unsigned long _last_button_pressed_time = 0;
};


#endif //ButtonRow_h
