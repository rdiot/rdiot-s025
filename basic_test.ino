/* 4x4 Matrix 16 Keypad Keyboard Module [S025] : http://rdiot.tistory.com/131 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};

byte rowPins[numRows] = {2,3,4,5}; //Rows 0 to 3
byte colPins[numCols]= {6,7,8,9}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S025:4x4 16 keypad");

  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
   // Serial.print(keypressed);
    lcd.setCursor(0,1);
    lcd.print("keypressed=" + (String)keypressed + "  ");

    switch (keypressed)
    {
      case '0':
           lcd.setCursor(0,2);
           lcd.print("if=0, then action");      
        break;
      case 'F':
           lcd.setCursor(0,2);
           lcd.print("if=F, then action");      
        break;  
      default:
          lcd.setCursor(0,2);
           lcd.print("if=defulat       "); 
        break;
    }

  }

}
