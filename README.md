# Heart Rate Monitoring System

We have developed a low-cost heart rate monitoring system that provides real-time feedback on the user's heart rate. The system uses a MAX30102 sensor to detect the user's pulse and calculate their heart rate. The heart rate data is then displayed on an I2C display, allowing the user to easily read their current BPM. Additionally, the system includes a piezo buzzer that beeps in sync with the user's pulse, providing an additional feedback mechanism. The system is designed to be compact and easy to use, making it suitable for a range of applications, from personal health tracking to exercise monitoring. Overall, our heart rate monitoring system provides a simple yet effective way to monitor and track heart rate in real-time.

## Materials Used

- **Arduino Uno:** This is the microcontroller that processes data from the MAX30102 sensor and displays it on the LCD screen. It is the heart of the system and controls all the other components.
- **16x2 LCD I2C Interface:** This is a Liquid Crystal Display (LCD) module that uses an I2C interface to communicate with the Arduino Uno. The 16x2 LCD is used to display heart rate readings in real-time.
- **MAX30102 Sensor:** This is a pulse oximeter and heart rate sensor that is used to measure the patient's heart rate. The sensor is placed on the patient's finger, and the readings are sent to the Arduino Uno for processing.
- **Piezo Buzzer:** This is an audio output device that produces a sound when the heart rate exceeds a predetermined threshold. The piezo buzzer is used to alert the patient or healthcare professional of any abnormalities.
- **Acrylic Transparent Casing for Arduino Uno:** The Arduino Uno is placed inside a transparent acrylic casing to protect it from physical damage while allowing easy access to the internal components.
- **Dupont/Jumper wires:** These are wires used to connect the various system components, such as the MAX30102 sensor and the piezo buzzer, and the I2C interface to the Arduino Uno microcontroller.
- **9V Battery & Connector with DC Jack:** This is the power source for the Arduino Uno and other system components. The DC jack is used to connect the battery to the Arduino Uno.
- **Illustration Board:** This board was used as a base for the system and to hold the various components in place during assembly.

## Group Members

- De Juan, Carl Anthony II
- Deauna, Renz Jerome
- Descalzo, Darelle
- Llandelar, A-Jay
- Sinogaya, Joshua Gabriel

## Code

The code for the real-time heart rate monitoring system using Arduino Uno is written in C++ programming language. The code utilizes the MAX30105 sensor library to collect heart rate data and the LiquidCrystal_I2C library to display the data on a 16x2 LCD screen. The heart rate is displayed in beats per minute (BPM), and a piezo buzzer is used to alert the patient or healthcare professional if the heart rate exceeds a predetermined threshold.

The code begins with the inclusion of the necessary libraries, including Wire.h, MAX30105.h, LiquidCrystal_I2C.h, and heartRate.h. An array of bytes is then defined to create a heart symbol to display on the LCD screen. The setup function initializes the system by configuring the Arduino Uno pins and initializing the LCD screen. The MAX30105 sensor is also initialized, and the pulse amplitudes for the red and green LEDs are set to 0x0A and 0, respectively.

The loop function continuously checks for a heart rate signal from the MAX30102 sensor. If a heartbeat is detected, a tone is played on the piezo buzzer to indicate a heartbeat. The heart rate is then calculated using the time between beats, and the average heart rate is computed based on the last four heart rate readings. If a finger is not detected, the LCD screen displays "No Finger," and the piezo buzzer produces a continuous sound. If a finger is detected, the LCD screen displays the current heart rate in BPM, and the piezo buzzer is silenced.

Overall, the code for the real-time heart rate monitoring system using Arduino Uno is relatively simple and easy to understand. The libraries used and the programming language make it easy to integrate and modify the code for different applications and use cases.

## Assembly Instructions

### Connecting the MAX30102 Sensor to the Arduino Uno

1. Connect the VCC into the 5V pin of the Arduino
2. Connect the SCL into the SCL pin of the Arduino
3. Connect the SDA into the SDA pin of the Arduino
4. Connect the GND into the GND pin of the Arduino

### Connecting the I2C 16x2 Interface

1. Connect the VCC into the 5V pin of the Arduino
2. Connect the SDA into the A4 pin of the Arduino
3. Connect the SCL into the A5 pin of the Arduino
4. Connect the GND into the GND pin of the Arduino

### Connecting the Piezo Buzzer

1. Connect the positive into the PWM~3 of the Arduino
2. Connect the Negative into the GND pin of the Arduino

### Connecting 9V Power

1. Connect the 9V battery connector to the barrel jack socket of the Arduino Uno

### Connecting the USB data cable

1. Connect the USB A end of the data cable to the computer
2. Connect the USB B end of the data cable to the Arduino
