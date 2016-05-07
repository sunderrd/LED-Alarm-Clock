
//TO DO:
//-Hour up
//-Alarm display?
//-Louder alarm?
//-Tidy up

//TEST:
//-Bonus mode

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
unsigned long bonus_count;
unsigned long analog_last_second;
unsigned long last_sound_time;
unsigned long last_pong_time;
unsigned long last_time_flash;
unsigned long last_debounce_time;
boolean flash_on;
boolean sound_on;
boolean alarm_on;
boolean pressed_pointer[7];
Time clk;
Time alrm;
//-----------//

void setup() {
  //Serial.begin(9600);
  matrix.begin();
  chars_setup();
  circ_setup();

  //temp
  //clk.hour = 12;
  //clk.minute = 0;
  //mode = ANALOG;
}

void loop() {
  update_time();
  check_alarm();
  mode_select();
  execute_mode();
}
