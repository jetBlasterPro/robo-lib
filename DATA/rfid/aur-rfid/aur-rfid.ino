#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int RedLed = 5;
const int GreenLed = 6;
const int Buzzer = 7;
int count = 0;
char c;
String id;
int wait = 2000;
void setup() {
  Serial.begin(9600);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.println("Please Scan your RFID Card");
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print(" THE SOLUTIONS ");
  lcd.setCursor(0, 1);
  lcd.print(" RFID BASED LOCK SYSTEM");
  lcd.setCursor(0, 2);
  lcd.print(" CARD:");
  lcd.setCursor(0, 3);
  lcd.print(" NAME:");
}
void loop() {
  while (Serial.available() > 0) {
    c = Serial.read();
    count++;
    id += c;
    if (count == 12) {
      Serial.print(id);
      //break;
      if (id == "EARTH4089561") {
        Serial.println("Vaild Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VAILD");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: PRATHAM");
        digitalWrite(GreenLed, HIGH);
        delay(wait);
        digitalWrite(GreenLed, LOW);
        digitalWrite(Buzzer, HIGH);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:");
      } else if (id == "FIRE40957894") {
        Serial.println("Vaild Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VAILD");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: Pranav");
        digitalWrite(GreenLed, HIGH);
        delay(wait);
        digitalWrite(GreenLed, LOW);
        digitalWrite(Buzzer, HIGH);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:");
      } else if (id == "WATER4089974") {
        Serial.println("Vaild Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VAILD");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: Prateek");
        digitalWrite(GreenLed, HIGH);
        delay(wait);
        digitalWrite(GreenLed, LOW);
        digitalWrite(Buzzer, HIGH);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:");
      } else {
        Serial.println("Invaild Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: INVAILD");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: UNKNOWN");
        digitalWrite(RedLed, HIGH);
        digitalWrite(Buzzer, HIGH);
        delay(500);
        digitalWrite(Buzzer, LOW);
        delay(2000);
        digitalWrite(RedLed, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:");
      }
    }
  }
  count = 0;
  id = "";
  delay(500);
}
