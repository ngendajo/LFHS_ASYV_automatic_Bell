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
//---- MONDAY bell ------//
const int h1D1 = 6; const int m1D1 = 30;
const int h2D1 = 7; const int m2D1 = 00;
const int h3D1 = 7; const int m3D1 = 15;
const int h4D1 = 7; const int m4D1 = 20;
const int h5D1 = 8; const int m5D1 = 50;
const int h6D1 = 10; const int m6D1 = 25;
const int h7D1 = 12; const int m7D1 = 00;
const int h8D1 = 12; const int m8D1 = 30;
const int h9D1 = 12; const int m9D1 = 45;
const int h10D1 = 13; const int m10D1 = 45;
const int h11D1 = 14; const int m11D1 = 50;
const int h12D1 = 15; const int m12D1 = 55;
const int h13D1 = 16; const int m13D1 = 15;
const int h14D1 = 17; const int m14D1 = 15;
const int h15D1 = 18; const int m15D1 = 00;
const int h16D1 = 18; const int m16D1 = 40;
const int h17D1 = 18; const int m17D1 = 50;
const int h18D1 = 20; const int m18D1 = 50;
////////////////////////////////////////////////////
//---- TUESDAY bell ------//
const int h1D2 = 6; const int m1D2 = 30;
const int h2D2 = 7; const int m2D2 = 00;
const int h3D2 = 7; const int m3D2 = 15;
const int h4D2 = 7; const int m4D2 = 20;
const int h5D2 = 8; const int m5D2 = 50;
const int h6D2 = 10; const int m6D2 = 25;
const int h7D2 = 12; const int m7D2 = 00;
const int h8D2 = 12; const int m8D2 = 30;
const int h9D2 = 12; const int m9D2 = 45;
const int h10D2 = 13; const int m10D2 = 45;
const int h11D2 = 14; const int m11D2 = 50;
const int h12D2 = 15; const int m12D2 = 00;
const int h13D2 = 17; const int m13D2 = 15;
const int h14D2 = 18; const int m14D2 = 00;
const int h15D2 = 18; const int m15D2 = 40;
const int h16D2 = 18; const int m16D2 = 50;
const int h17D2 = 20; const int m17D2 = 50;
////////////////////////////////////////////////////
//---- WEDNESDAY bell ------//
const int h1D3 = 6; const int m1D3 = 30;
const int h2D3 = 7; const int m2D3 = 00;
const int h3D3 = 7; const int m3D3 = 15;
const int h3D3a = 7; const int m3D3a = 20;
const int h4D3 = 8; const int m4D3 = 50;
const int h5D3 = 10; const int m5D3 = 25;
const int h6D3 = 12; const int m6D3 = 00;
const int h7D3 = 12; const int m7D3 = 30;
const int h8D3 = 12; const int m8D3 = 45;
const int h9D3 = 13; const int m9D3 = 45;
const int h10D3 = 14; const int m10D3 = 50;
const int h11D3 = 15; const int m11D3 = 55;
const int h12D3 = 16; const int m12D3 = 15;
const int h13D3 = 17; const int m13D3 = 15;
const int h14D3 = 18; const int m14D3 = 00;
const int h15D3 = 18; const int m15D3 = 40;
const int h16D3 = 18; const int m16D3 = 50;
const int h17D3 = 20; const int m17D3 = 50;
////////////////////////////////////////////////////
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
const int h12D4 = 15; const int m12D4 = 15;
const int h13D4 = 18; const int m13D4 = 00;
const int h14D4 = 18; const int m14D4 = 40;
const int h15D4 = 18; const int m15D4 = 50;
const int h16D4 = 19; const int m16D4 = 50;
const int h17D4 = 20; const int m17D4 = 55;
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
if(daysOfWeek[dayOfWeek]=="Monday"){
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
if (H == h14D1 && M == m14D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h15D1 && M == m15D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h16D1 && M == m16D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h17D1 && M == m17D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h18D1 && M == m18D1 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}
////////////////////////////////////// DAY TWO //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else if(daysOfWeek[dayOfWeek]=="Tuesday"){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D2 && M == m1D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D2 && M == m2D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D2 && M == m3D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h4D2 && M == m4D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h5D2 && M == m5D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h6D2 && M == m6D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h7D2 && M == m7D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h8D2 && M == m8D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h9D2 && M == m9D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h10D2 && M == m10D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h11D2 && M == m11D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h12D2 && M == m12D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h13D2 && M == m13D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h14D2 && M == m14D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h15D2 && M == m15D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h16D2 && M == m16D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h17D2 && M == m17D2 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
}
////////////////////////////////////// DAY three //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
else if(daysOfWeek[dayOfWeek]=="Wednesday"){
digitalWrite(indicator1, HIGH);
digitalWrite(indicator2, HIGH);
digitalWrite(indicator3, HIGH);
if (H == h1D3 && M == m1D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h2D3 && M == m2D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D3 && M == m3D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h3D3a && M == m3D3a && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h4D3 && M == m4D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h5D3 && M == m5D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h6D3 && M == m6D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h7D3 && M == m7D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h8D3 && M == m8D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h9D3 && M == m9D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h10D3 && M == m10D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h11D3 && M == m11D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h12D3 && M == m12D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h13D3 && M == m13D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h14D3 && M == m14D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h15D3 && M == m15D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h16D3 && M == m16D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h17D3 && M == m17D3 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
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
if (H == h15D4 && M == m15D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h16D4 && M == m16D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
if (H == h17D4 && M == m17D4 && S == 0) { for (i = 0; i < Lenght; i++) { digitalWrite(bell, LOW); delay(1000); } digitalWrite(bell, HIGH); i = 0; }
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
