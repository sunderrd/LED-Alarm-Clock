
//TO DO:
//-COLOR COLOR COLOR COLOR !!!!!!!!!!
//-Buttons; needed helper fucntions (shift register reading?)
//-Sound
//-Debounce?
//-Tidy up
//-Combine last_time vars? need more than one? no param or pointer?

//TEST:
//-Analog read
//-Analog clock rewrite hand
//-Sound
//-Mode switch
//-Bonus mode
//-Pong background update

//NOTES
//-Odd error with numbers of size 2



//--Libraries--//
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <Definitions.h>
//--End--//

//--GLOBALS--//
long y[32];
int color;
int mode;
unsigned long last_time;
unsigned long analog_last_second;
unsigned long last_sound_time;
unsigned long last_pong_time;
unsigned long last_time_flash;
boolean flash_on;
Time clk;
Time alarm;
//-----------//

void setup() {
  Serial.begin(9600);
  matrix.begin();
  chars_setup();
  circ_setup();

  //temp
  clk.hour = 11;
  clk.minute = 24;
  mode = TIME_SET;
}

void loop() {
  update_time();
  mode_select();
  execute_mode();
}
