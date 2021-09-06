#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led = 7;
int buzzer = 6;
int sensor = A0;
const int temperaturePin = A1;
int thre = 500 ;

void setup()
{
  lcd.print("    Welcome");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("       To        "); 
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     AIR");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("QUALITY MONITOR");  
  delay(1000); 
  lcd.clear();
  pinMode(led,OUTPUT );
  pinMode(buzzer,OUTPUT );
  pinMode(sensor,INPUT );
  pinMode(temperaturePin,INPUT );
}
float getVoltage(int pin)
{
  
  return (analogRead(pin) * 0.004882814);
}
void loop()
{
  int analogValue=analogRead(sensor);
  
  float voltage, degreesC;
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  lcd.setCursor (0, 0);
  lcd.print ("Air Qual:");
  lcd.print (analogValue);
  lcd.print (" PPM");
  
  lcd.setCursor (0,1);
  
  if(analogValue<=50)
  {
    lcd.print("FA ");
    delay(1000);
  	lcd.clear();
  } 

   else if(analogValue>50 && analogValue<=100)
  {
    lcd.print("Mod ");
    tone(buzzer , 10, 10000 ) ;
    delay(1000);
  	lcd.clear();
  }
  if(analogValue>100  && analogValue<=150)
  {
    lcd.print("MU ");
    tone(buzzer , 100, 10000 ) ;
    delay(1000);
  	lcd.clear();
  } 
  if(analogValue>150  && analogValue<=200)
  {
    lcd.print("UN ");
    digitalWrite(led , HIGH );
    tone(buzzer , 1000, 10000 ) ;
    delay(1000);
  	lcd.clear();
  } 
  if(analogValue>200)
  {
    lcd.print("VU ");
    digitalWrite(led , HIGH );
    tone(buzzer , 10000, 10000 ) ;
    delay(1000);
  	lcd.clear();
  } 
  lcd.print(degreesC);
  lcd.print(" deg C");
  delay(1000);
  lcd.clear();
}