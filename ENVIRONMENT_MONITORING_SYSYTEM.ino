#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define DHTPIN 8       
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
const int ldrPin=A0;
const int ledPin=6;
const int buzzerPin=7;
float temperature;
float humidity;
int ldrValue;
  
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);

  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ENV MONITOR");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM");
  delay(2000);
 // lcd.clear();
}
void loop() {
  temperature=dht.readTemperature();
  humidity=dht.readHumidity();
  ldrValue=analogRead(ldrPin);

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0,1);
  lcd.print("Light:");
  lcd.print(ldrValue);
  lcd.print(" ");

  if(ldrValue>300 || temperature>300){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
}

  
