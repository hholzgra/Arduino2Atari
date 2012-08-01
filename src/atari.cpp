#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <LiquidCrystal.h>

#define analogLow 60
#define analogHigh 200

#define JOY1_LEFT    22
#define JOY1_RIGHT   23
#define JOY1_UP      24
#define JOY1_DOWN    25
#define JOY1_TRIGGER 26

#define JOY1_LEFT    32
#define JOY1_RIGHT   33
#define JOY1_UP      34
#define JOY1_DOWN    35
#define JOY1_TRIGGER 36

#define SIO_CMD      40
#define SIO_TRX      18
#define SIO_RCV      19

ArduinoNunchuk nunchuk = ArduinoNunchuk();
 
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

 
byte dirchar[8][8] = 
{
  { // links oben
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  },
  { // links 
  B00000,
  B00000,
  B00000,
  B01000,
  B10000,
  B01000,
  B00000,
  B00000,
  },
  { // links unten
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B11000,
  },
  { // oben
  B00100,
  B01010,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  },
  { // unten
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01010,
  B00100,
  },
  { // rechts oben
  B00011,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  },
  { // rechts 
  B00000,
  B00000,
  B00000,
  B00010,
  B00001,
  B00010,
  B00000,
  B00000,
  },
  { // rechts unten
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B00011,
  },
};

void setup()
{
 int i;
 
 nunchuk.init(); 
 
 for (i = 0; i <8 ; i++) {
   lcd.createChar(i, dirchar[i]);
 }
 
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Arduino -> ATARI"); // print a simple message
 
 for (i = 22; i <= 26; i++) {
   pinMode(i, OUTPUT);
 }
}
  
void loop()
{
 nunchuk.update();  
  
  /*
 lcd.setCursor(0,1);

 if (nunchuk.analogX < analogLow) {
   if (nunchuk.analogY < analogLow) {
     lcd.write((uint8_t)2);
   } else if (nunchuk.analogY > analogHigh) {
     lcd.write((uint8_t)0);
   } else {
     lcd.write((uint8_t)1);
   }     
 } else  if (nunchuk.analogX > analogHigh) {
   if (nunchuk.analogY < analogLow) {
     lcd.write((uint8_t)7);
   } else if (nunchuk.analogY > analogHigh) {
     lcd.write((uint8_t)5);
   } else {
     lcd.write((uint8_t)6);
   }   
 } else {
   if (nunchuk.analogY < analogLow) {
     lcd.write((uint8_t)4);
   } else if (nunchuk.analogY > analogHigh) {
     lcd.write((uint8_t)3);
   } else {
     lcd.print(" ");
   }   
 }

 lcd.print(" ");
 lcd.print(nunchuk.zButton ? "*" : " ");
 
 lcd.print(" x:"); lcd.print(nunchuk.analogX);
 lcd.print(" y:"); lcd.print(nunchuk.analogY);
 */
 
 digitalWrite(JOY1_LEFT,   (nunchuk.analogX < analogLow)  ? LOW : HIGH);
 digitalWrite(JOY1_RIGHT,  (nunchuk.analogX > analogHigh) ? LOW : HIGH);
 digitalWrite(JOY1_UP,     (nunchuk.analogY < analogLow)  ? LOW : HIGH);
 digitalWrite(JOY1_DOWN,   (nunchuk.analogY > analogHigh) ? LOW : HIGH);
 digitalWrite(JOY1_TRIGGER, nunchuk.cButton               ? LOW : HIGH);
 
 delay(100);
}
