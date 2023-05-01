#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
int IRSensor = 9; 
int counter = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(IRSensor, INPUT);
  lcd.init();
  lcd.clear();         
  lcd.backlight();     
  
  lcd.setCursor(1,0);  
  lcd.print("VEHICLE COUNTER");

  lcd.setCursor(4,1);  
  lcd.print("COUNTER=");
  
  lcd.setCursor(12,1);  
  lcd.print(counter);
}

void loop() {
  int sensorStatus = digitalRead(IRSensor);
  if (sensorStatus == 0) 
{
  counter += 1; 
  Serial.println(counter); 
  lcd.clear();
  lcd.setCursor(1,0);  
  lcd.print("VEHICLE COUNTER");

  lcd.setCursor(4,1);  
  lcd.print("COUNTER=");
  
  lcd.setCursor(12,1);  
  lcd.print(counter);
  delay(500);
  }
}
