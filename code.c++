#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

#define BUZZER 25
#define BUTTON 26
#define TEMP_SENSOR 34

HardwareSerial sim800(1);


int medHour = 12;
int medMinute = 5;

bool medicineTaken = false;
bool smsSent = false;
unsigned long reminderStart;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  rtc.begin();

  sim800.begin(9600, SERIAL_8N1, 16, 17);

  lcd.print("Patient System");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  float temp = readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());

  if (now.hour() == medHour && now.minute() == medMinute && !medicineTaken) {
    digitalWrite(BUZZER, HIGH);
    reminderStart = millis();
    lcd.clear();
    lcd.print("Take Medicine!");
  }

  if (digitalRead(BUTTON) == LOW) {
    medicineTaken = true;
    digitalWrite(BUZZER, LOW);
    lcd.clear();
    lcd.print("Medicine Taken");
    delay(2000);
    lcd.clear();
  }

 
  if (!medicineTaken && millis() - reminderStart > 60000 && !smsSent) {
    sendSMS("ALERT: Patient missed medicine!");
    smsSent = true;
  }

  if (temp > 38.0) {
    sendSMS("EMERGENCY: High body temperature!");
    delay(60000);
  }

  delay(1000);
}

float readTemperature() {
  int val = analogRead(TEMP_SENSOR);
  return (val * 3.3 * 100) / 4095;
}

void sendSMS(String message) {
  sim800.println("AT+CMGF=1");
  delay(1000);
  sim800.println("AT+CMGS=\"+91XXXXXXXXXX\""); // caretaker number
  delay(1000);
  sim800.print(message);
  delay(500);
  sim800.write(26);
}
