

#include <Arduino.h>
#include <LiquidCrystal.h>


 #define debug  
 #undef debug  //leave in to prevent printing (go down to set-up and comment out serial.begin). Comment out to allow printing.
 #ifdef debug
 #define sprint(x) Serial.print(x) 
 #define sprintl(x) Serial.println(x) 
 #else
 #define sprint(x)
 #define sprintl(x)
#endif


enum colors_t
{
  red,
  green,
  blue
}; // used in arrays as index [0] [1] [2]


/////////////////////  State of day for LED activity

enum stateOfDay_t
{
  idle,  
  sunrising,
  daytime,
  sunseting,
  night_flicker,
  night_OnOff,
  
}; // used to know which functions to call

enum boolArrays_t
{
  LED_Off,
  LED_flicker,
  LED_switchable
}; // used as index in an array of booleans to know which LEDs are off/on, whether theuy are 'flickering' (simulated variation) LED_switchable not currently used








///////////////////// LED which are not needed. They could be used as indicators


//Indicators that have two roles either to show color change when user editing or display function when lights under auto control
//#define LEDred_sunrise      A1
//#define LEDgreen_daytime    A2
//#define LEDblue_sunset      A3
//#define LEDincrease_night-F A4
//#define LEDdecrease_night_O A5

//#define LED A6

//#define LED 2
//#define LED 3

//#define LED 11
//#define LED 12

/////////////////////////// LCD 1602 display for user input/output

// LiquidCrystal lcd(12, 11, 10, 9, 8, 7);// This is set on a simulator. May not theyMatch the actual hardware<<<<<
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // the read/write pin not connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

////////////////////////////////////////////////  enums and global variables

enum stateOfbutton_t   // 5 push button inputs read by analogue voltage
{
    unknown,
    select,
    left,
    up,
    down,
    right
}; 
// The values read in the function will need to be changed to match the actual buttons/voltages if using a different set
stateOfbutton_t buttonState = unknown; // buttonState is used to record which button was pressed

enum stateOfMenu_t
{
    MenuUnknown, // initial state
    
    showMain1,
    
    show2Color,
    show2Flicker,
    show2Day,
    show2OnOff, // level 2 of hierarchy of menu

    show3Hue,    show4Saturate,    show5Intense, //show6Color,
    show3Flicker,  show4Flicker,
    show3Day,
    show3OnOff, // level 3

 


    selectLED,
    showNoMenu
};

stateOfMenu_t menuState = MenuUnknown; // menuState records which menu is to be displayed or is being displayed
// (when bottom level of the menu reached the program needs to change to handle the actions required)

enum pointTo_t   // used to point to menu items on the lcd display
{
    arrowLeft,
    arrowRight
};




void readButtonDefineState(); // declared here as called before function definition
void fancyPrint(char);
//void displayTopRowMenuItems(const char*, pointTo_t, const char);