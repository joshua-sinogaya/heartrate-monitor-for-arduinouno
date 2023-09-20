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

## Usage

1. Connect the MAX30102 sensor to the Arduino Uno using Dupont/Jumper wires.
2. Attach the 16x2 LCD I2C interface to the Arduino Uno.
3. Place the MAX30102 sensor on the patient's finger.
4. Power on the system using the 9V battery and DC jack.
5. The heart rate data will be displayed on the 16x2 LCD in real-time, and the piezo buzzer will beep in sync with the heart rate.

Feel free to customize and enhance this system for your specific needs!
