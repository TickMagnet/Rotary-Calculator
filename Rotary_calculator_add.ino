// A rotary calculator for kids to learn adding numbers
//         Peter Liwyj Jan 19 2021

//                Materials
//      one breadboard and jumper wires 
//          one I2C 1602 display
//        two 10k potentiometers
//               one Arduino 
//           one programming cable

//               LCD wiring 
//    LCD Ground     to    Arduino Ground
//    LCD VCC pin    to    Arduino 5V out pin
//    LCD SDA pin    to    Arduino A4 pin
//    LCD SCL pin    to    Arduino A5 pin

//           Potentiometer #1 wiring
//      Left leg     to    Arduino Ground pin
//      Right leg    to    Arduino 5V out pin
//      Middle leg   to    Arduino A1 pin

//           Potentiometer #2 wiring
//      Left leg     to   Arduino Ground pin
//      Right leg    to   Arduino 5V out pin
//      Middle leg   to   Arduino A2 pin


#include <LiquidCrystal_I2C.h>  //Use the I2C protocol to talk to your display

// These two constants below won't change. They're used to give names to the analog pins used:

const int analogInPin1 = A1;  // Analog input pin that the first potentiometer is attached to
const int analogInPin2 = A2;  // Analog input pin that the second potentiometer is attached to

int sensorValue1 = 0;        // make an integer and read from pot1
int sensorValue2 = 0;        // make an integer and read from pot2
int outputValue1 = 0;        // make an integer and keep output value 1 in it
int outputValue2 = 0;        // make an integer and keep output value 2 in it

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
                                   // if your display doesn't work it may have a different I2C address
                                   // adjust the pot on the display's back to change brightness

void setup()              // do all this once
{
  lcd.backlight();        // turn the backlight on
  lcd.init();             // initialize the lcd 

  lcd.setCursor(0,0);             // set the cursor to the first space of the first line
  lcd.print("     Rotary    ");   // Type "Rotary" in the middle of the first line
  lcd.setCursor(0,1);             // set the cursor to the first space of the second line
  lcd.print("   Calculator    ");  // type "Calculator" in the middle of the second line
  
  delay (1500);                   // delay 1.5 seconds
  
  lcd.setCursor(0,0);             // set the cursor to the first space of the first line
  lcd.print(" Spin the dials ");  // type "Spin the dials" in the middle of the first line
  lcd.setCursor(0,1);             // set the cursor to the first space of the second line
  lcd.print("to change number");  // type "to change the number" on the second line
  
  delay (3000);                   //Delay 3 seconds
  lcd.init();             // initialize the lcd again to make it blank
}

void loop()       // do this a bunch of times
{
  
    // read the analog in value of pot1:
  sensorValue1 = analogRead(analogInPin1);
    // read the analog in value of pot2:
  sensorValue2 = analogRead(analogInPin2);
  // map pot1 to the range of the analog out:
  outputValue1 = map(sensorValue1, 0, 1023, 1, 100);
    // map pot2 to the range of the analog out:
  outputValue2 = map(sensorValue2, 0, 1023, 1, 100);
  
    //move the cursor to the first space (0) of the first line (0)
  lcd.setCursor(0, 0);
    // display "Let's ADD today!" on first line
  lcd.print("Let's ADD today!");
  
    //move the cursor to the first space (0) of the second line (1)
  lcd.setCursor(0, 1);
    // display pot 1 as a number from 1 to 100 where the cursor is
  lcd.print(outputValue1);
    // print a space then a plus sign then another space
  lcd.print(" + ");
    // display pot 2 as a number from 1 to 100 where the cursor is after the plus sign
  lcd.print(outputValue2);
    // display a space then an equals sign then another space
  lcd.print(" = ");
    // display the two numbers added together to the right of the displayed numbers
  lcd.print(outputValue1 + outputValue2);
  
    // this writes blanks behind the answer. I could initialize to erase but that flickers
    // this also makes the numbers change smoother than blanking the whole screen
  lcd.print("       ");


}
