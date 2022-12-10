
#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
dht DHT;
#define DHT11_PIN 8

void setup()
{
                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  delay(200);
}


void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
  int tempF = ((temp*(1.8)) + 32);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  
  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1500);
  
}
