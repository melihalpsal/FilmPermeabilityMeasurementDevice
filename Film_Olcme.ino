#include <QTRSensors.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  pinMode(A2, INPUT); 
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  digitalWrite(8, LOW);
  digitalWrite(6, LOW); 
  digitalWrite(7, HIGH); 
   digitalWrite(10, HIGH);
  delay(1000);
}

void loop() 
{

  if(digitalRead(9) == HIGH)
  {
  float result = (analogRead(A2)-564)/1.21;
  if(result < 0) result=0;
  if(result > 100) result=100;
  lcd.print(String("%") + String(result));
  if(result<5.01)
  {lcd.setCursor(0,1);
    lcd.print("SD.Black");}
  else if(result<20.01)
  {lcd.setCursor(0,1);
    lcd.print("D.Black");}
  else if(result<35.01)
  {lcd.setCursor(0,1);
    lcd.print("Black");}
  else if(result<50.01)
  {lcd.setCursor(0,1);
    lcd.print("L.Black");}
  else if(result<70.01)
  {lcd.setCursor(0,1);
    lcd.print("Defective");}
  else
  {lcd.setCursor(0,1);
    lcd.print("Impeccable");}
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  }

}
