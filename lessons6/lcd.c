
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Loading.....");
  delay(700);
  lcd.setCursor(0, 0);
  lcd.print("Welcome     ");
  delay(800);
  lcd.setCursor(0, 0);
  lcd.print("Input content:"); 
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
   lcd.setCursor(0, 1);
  lcd.print(Serial.readString());
  }
}
 