🏥 Smart Patient Medicine Reminder System (ESP32 + GSM)

An IoT-based healthcare system built using ESP32 and GSM to ensure patients never miss their medication and caregivers are alerted in real time during emergencies.

📌 Problem Statement

Patients—especially elderly and chronically ill—often forget to take medicines on time.
Missed doses and delayed medical attention can lead to serious health risks.

💡 Solution

This project provides an automated medicine reminder and patient monitoring system that:

Reminds patients at scheduled times

Detects missed doses

Sends SMS alerts to caregivers

Monitors body temperature

Sends emergency alerts when abnormal conditions are detected

🚀 Features

⏰ Timed medicine reminders

🔔 Buzzer alert

📟 LCD display notifications

📩 SMS alert for missed medicine

🌡️ Body temperature monitoring

🚨 Emergency alert system

⚡ Low-cost & scalable design

🧠 System Workflow

Medicine time is reached

Buzzer and LCD notify the patient

Patient presses button after taking medicine

If not taken within 1 minute → SMS sent to caretaker

If body temperature exceeds threshold → Emergency SMS alert

🔧 Hardware Components

ESP32

SIM800L GSM Module

DS3231 RTC Module

LM35 Temperature Sensor

Push Button

Buzzer

LCD Display (I2C)

External 4V power supply (for SIM800L)

🔌 Pin Connections
Component	ESP32 Pin
SIM800L RX	GPIO 17
SIM800L TX	GPIO 16
Buzzer	GPIO 25
Medicine Button	GPIO 26
LM35	GPIO 34
LCD SDA	SDA
LCD SCL	SCL

⚠️ Important: SIM800L must be powered externally (3.7–4.2V).

📦 Software & Libraries

Install the following Arduino libraries:

RTClib

LiquidCrystal_I2C

🛠️ How to Run the Project

Connect all components as per the pin table

Install required libraries

Update the caretaker phone number in the code:

AT+CMGS="+91XXXXXXXXXX"


Set medicine time in the code

Upload the code to ESP32

Insert SIM card into SIM800L

Power the system and test# Smart-Patient-Medicine-Reminder
