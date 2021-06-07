#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(200);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      String serialIn = Serial.readString();
      if (serialIn.equals("LED_ON")){
        digitalWrite(LED_BUILTIN, HIGH);
        break;
      } 
      if (serialIn.equals("LED_OFF")){
        digitalWrite(LED_BUILTIN, LOW);
        break;
      }
      // display each character to the LCD
      lcd.print(serialIn);
    }
  }
}
