#include <EEPROM.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char *daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const int bell = 10;
int Emergency = 8;
const int Lenght = 6;
int i = 0;
int H;//Hours
 int M;//Minutes
int S;///Seconds
int dayOfWeek;//day

int indicator1=2;//LED status of monday
int indicator2=3;//LED status of Tuesday, Wenesdy, Thursday
int indicator3=4;//LED status of Friday

////////////////////////////////////////////////////
//---- MONDAY to WEDNESDAY bell ------//
const int h1D1 = 6; const int m1D1 = 30;
const int h2D1 = 7; const int m2D1 = 00;
const int h3D1 = 7; const int m3D1 = 20;
const int h4D1 = 9; const int m4D1 = 20;
const int h5D1 = 9; const int m5D1 = 45;
const int h6D1 = 11; const int m6D1 = 50;
const int h7D1 = 12; const int m7D1 = 00;
const int h8D1 = 13; const int m8D1 = 15;
const int h9D1 = 13; const int m9D1 = 30;
const int h10D1 = 15; const int m10D1 = 30;
const int h11D1 = 18; const int m11D1 = 00;
const int h12D1 = 18; const int m12D1 = 45;
const int h13D1 = 20; const int m13D1 = 50;

//---- THURSDAY bell ------//
const int h1D4 = 6; const int m1D4 = 30;
const int h2D4 = 7; const int m2D4 = 00;
const int h3D4 = 7; const int m3D4 = 15;
const int h4D4 = 7; const int m4D4 = 20;
const int h5D4 = 8; const int m5D4 = 50;
const int h6D4 = 10; const int m6D4 = 25;
const int h7D4 = 12; const int m7D4 = 00;
const int h8D4 = 12; const int m8D4 = 30;
const int h9D4 = 12; const int m9D4 = 45;
const int h10D4 = 13; const int m10D4 = 45;
const int h11D4 = 14; const int m11D4 = 50;
const int h12D4 = 18; const int m12D4 = 00;
const int h13D4 = 18; const int m13D4 = 50;
const int h14D4 = 19; const int m14D4 = 50;
////////////////////////////////////////////////////
//---- FRIDAY bell ------//
const int h1D5 = 6; const int m1D5 = 30;
const int h2D5 = 6; const int m2D5 = 40;
const int h3D5 = 7; const int m3D5 = 15;
const int h4D5 = 7; const int m4D5 = 20;
const int h5D5 = 8; const int m5D5 = 50;
const int h6D5 = 10; const int m6D5 = 25;
const int h7D5 = 12; const int m7D5 = 00;
const int h8D5 = 13; const int m8D5 = 00;
////////////////////////////////////////////////////
//---- SATURDAY bell ------//
const int h1D6 = 18; const int m1D6 = 00;
const int h2D6 = 19; const int m2D6 = 00;
const int h3D6 = 21; const int m3D6 = 00;
////////////////////////////////////////////////////

void setup() 
{
  pinMode(indicator1, OUTPUT);
  pinMode(indicator2, OUTPUT);
  pinMode(indicator3, OUTPUT);
    lcd.init();
    lcd.backlight();
    pinMode(Emergency, INPUT);
    pinMode(bell, OUTPUT);
    digitalWrite(bell, HIGH);
    Serial.begin(9600);
    Serial.println("LFHS AUTOMATIC BELL");
    Serial.println("SCIENCE CENTER");
    delay(3000);
}

void loop() 
{
    int k = digitalRead(Emergency);
    if (k == 1) 
    {
     digitalWrite(bell, LOW);
    } 
    else 
    {
     digitalWrite(bell, HIGH);
    }

    tmElements_t tm;
    if (RTC.read(tm)) {
       H = tm.Hour;
       M = tm.Minute;
       S = tm.Second;
       dayOfWeek = weekday(tm.Day, tm.Month, tmYearToCalendar(tm.Year)) - 1;

        Serial.print("Time: ");
        Serial.print(H);
        Serial.print(":");
        Serial.print(M);
        Serial.print(":");
        Serial.print(S);
        Serial.print(" Date: ");
        Serial.print(tm.Day);
        Serial.print("/");
        Serial.print(tm.Month);
        Serial.print("/");
        Serial.print(tmYearToCalendar(tm.Year));
        Serial.print(" Day: ");
        Serial.println(daysOfWeek[dayOfWeek]);

        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("LFHS BELL");
        lcd.setCursor(1, 1);
        lcd.print("Time: ");
        lcd.print(H);
        lcd.print(":");
        lcd.print(M);
        lcd.print(":");
        lcd.print(S);
        lcd.setCursor(10, 0);
        lcd.print(daysOfWeek[dayOfWeek]);
    }
////////////////////////////////////// DAY 0NE //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
if((daysOfWeek[dayOfWeek]=="Monday") || (daysOfWeek[dayOfWeek]=="Tuesday") || (daysOfWeek[dayOfWeek]=="Wednesday")){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D1 && M == m1D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D1 && M == m2D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D1 && M == m3D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h4D1 && M == m4D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h5D1 && M == m5D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h6D1 && M == m6D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h7D1 && M == m7D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h8D1 && M == m8D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h9D1 && M == m9D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h10D1 && M == m10D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h11D1 && M == m11D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h12D1 && M == m12D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h13D1 && M == m13D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}

////////////////////////////////////// DAY FOUR //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else if(daysOfWeek[dayOfWeek]=="Thursday"){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D4 && M == m1D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D4 && M == m2D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D4 && M == m3D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h4D4 && M == m4D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h5D4 && M == m5D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h6D4 && M == m6D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h7D4 && M == m7D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h8D4 && M == m8D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h9D4 && M == m9D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h10D4 && M == m10D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h11D4 && M == m11D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h12D4 && M == m12D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h13D4 && M == m13D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h14D4 && M == m14D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}
////////////////////////////////////// DAY FIVE //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else if(daysOfWeek[dayOfWeek]=="Friday"){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D5 && M == m1D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D5 && M == m2D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D5 && M == m3D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h4D5 && M == m4D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h5D5 && M == m5D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h6D5 && M == m6D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h7D5 && M == m7D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h8D5 && M == m8D5 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}
////////////////////////////////////// DAY SIX //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else if(daysOfWeek[dayOfWeek]=="Saturday"){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D6 && M == m1D6 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D6 && M == m2D6 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D6 && M == m3D6 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}
////////////////////////////////////// DAY TWO, DAY THREE AND DAY FOUR //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else
{
 digitalWrite(bell, HIGH);
 digitalWrite(indicator1, LOW);
digitalWrite(indicator2, LOW);
digitalWrite(indicator3, LOW);
}
    delay(1000);
}

int weekday(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int dayOfWeek = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    return (dayOfWeek + 6) % 7 + 1;
}
