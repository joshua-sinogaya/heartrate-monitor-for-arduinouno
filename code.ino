
//Importing Libraries
#include <Wire.h>
#include "MAX30105.h"
#include <LiquidCrystal_I2C.h>
#include "heartRate.h"
//Heart Shape in I2C
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
MAX30105 particleSensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;

void setup()
{
  pinMode(3, OUTPUT);
  Serial.begin(115200);
  //Initializing I2C
  lcd.begin();
  lcd.backlight();
  lcd.createChar(1, heart);
  //Printing on the I2C
  lcd.home();
  lcd.print(" Heart  Monitor");
  lcd.setCursor(0,1);
  lcd.write(1);
  lcd.setCursor(2,1);
  lcd.print("Calibrating...");
  delay(7000);
  // Initializing the MAX30102 SENSOR
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1);
  }
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
}

void loop()
{
  long irValue = particleSensor.getIR();
  if (checkForBeat(irValue) == true) //Detecting the heart beat
  {
    //Beep the Piezo Buzzer at the same time as the heart beat 
    noTone(3);
    int beepDuration = 100; // Beep duration in milliseconds
    int beepFrequency = 1000; // Beep frequency in hertz
    tone(3, beepFrequency, beepDuration);
    
    long delta = millis() - lastBeat;
    lastBeat =   millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable
      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  //Printing the Heartrate BPM on the I2C Interface
  if (irValue < 50000) {
    lcd.setCursor(2,1);
    lcd.print("No Finger");
    tone(3, 1000);
  } else {
    if (beatAvg < 100){
      lcd.setCursor(2,1);
      lcd.print(" ");
      lcd.setCursor(3,1);
      lcd.print(beatAvg);
    } else {
      lcd.setCursor(2,1);
      lcd.print(beatAvg);
    }
    lcd.setCursor(5,1);
    lcd.print(" BPM       ");
  }
}
