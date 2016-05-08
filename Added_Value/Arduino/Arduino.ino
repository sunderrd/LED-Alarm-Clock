
/*
 * LED Alarm Clock
 * Created by: Ryan Sunderhaus
 * Completed May 8, 2016
 */

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
  matrix.begin();
  chars_setup();
}

void loop() {
  update_time();
  check_alarm();
  mode_select();
  execute_mode();
}
