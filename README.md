# Button Row library for Arduino
A library for making it easy to have multiple buttons connected to the same analog read pin. 
Using resistors one connects multiple buttons in parrallell with different resistors for each of the 
buttons. When a button is pressed the Arduino reads a different value for each of the buttons.
Up to 16 buttons are supported.

## Example usage
```cpp
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

#define OK 0
#define BACK 1
#define UP 2
#define DOWN 3
#define RESET 4 //UP and DOWN pressed at the same time

void loop() {
    switch (buttonRow.getPushedButton()) {
        case OK:
            Serial.println("one");
            break;
        case BACK:
            Serial.println("two");
            break;
        case UP:
            Serial.println("three");
            break;
        case DOWN:
            Serial.println("four");
            break;
        case RESET:
            Serial.println("five");
            break;
    }
    delay(100);
}
```

## Installation
1. Download as zip
2. Unzip
3. Copy the folder "ButtonRow" into arduino-x.x.x/libraries/ (x..x.x stands for version number)
4. restart the Arduino IDE


## Documentation

### ButtonRow
Constructor

#### Arguments

|type | name | description| default |
| --- | --- | --- | --- |
|int|analogPin|Analog pin to read from. The pin the button row is connected to.| |
|int[]|analogbutton_values|Array of int values of the analog value read for each of the buttons. A value between 0-1023. Used to identify what button was pressed. You can add combinations of values as buttons if you like as well see example usage. Supports up to 16 values.| |
|int|size|Number of buttons in the button row. C++ can not find the size of the array of buttons when it is sent to a class or function.| |
|int|threshold|The analog value is not perfect and can change some when read. The threshold value let you specify how large range you want to assign. Say the value is button value is 10 and the threshold is 5 then values from 5-15 will be assigned that button.| 2|
|int|repeat_click_timeout|When clicking a button it is easy that multiple clicks are registered instead of just one. A timeout has therefore been added to prevent this. This does not just delay but millis so it is non-blocking. A Value of 500, that is 500ms has been found to be a good value.|500|

To support more than 16 buttons edit `int _analog_button_values[16];` in `ButtonRow.h` to the desired number.

#### Use
```cpp
int button_values[] = {879, 181, 321, 985, 1024};
int size = sizeof(button_values) / sizeof(button_values[0]);
int threshold = 5;
int repeat_click_timeout = 500;
int analogIn = A0;
ButtonRow buttonRow(analogIn, button_values, size, threshold, repeat_click_timeout);
```


### getPushedButton
Method for posting weight to the API

#### Arguments
|type | name | description|
| --- | --- | --- | 

#### Returns
|type | description| 
|  --- | --- |
|int | The index of the button pressed as specified in the button_values when creating a ButtonRow. Returns -1 if no button is pressed. |

#### Use
```cpp
int button_values[] = {879, 181, 321, 985, 1024};
int size = sizeof(button_values) / sizeof(button_values[0]);
int threshold = 5;
int repeat_click_timeout = 500;
int analogIn = A0;
ButtonRow buttonRow(analogIn, button_values, size, threshold, repeat_click_timeout);

int pushed_button = buttonRow.getPushedButton();
```

## Authors

* **Dag Frode Solberg** - *Initial work* - [DagF](https://github.com/DagF)

See also the list of [contributors](https://github.com/trolllabs/arduino-button-row/contributors) who participated in this project.


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Trolllabs
* Smart Storage group
