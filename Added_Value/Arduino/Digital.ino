
//-------------DIGITAL-------------//
//---Handles digital clock display
//---Includes mode for setting
//-----times: clk and alrm
//---------------------------------//

const int HOUR_MAX = 23;
const int MINUTE_MAX = 59;

//--Displays classic digital clock
void basic_digital(Time disp_clock) {
  color = RED;
  
  write_num(disp_clock.hour/10, 0, 3, 2);
  write_num(disp_clock.hour%10, 7, 3, 2);
  
  filled_rect(15, 2, 5, 2);
  filled_rect(15, 2, 9, 2);
  
  write_num(disp_clock.minute/10, 19, 3, 2);
  write_num(disp_clock.minute%10, 26, 3, 2);
}

//--Sets primary time values
void set_clk(Time *clk_set) {
  basic_digital(*clk_set);
  
  //-Makes changes with buttons
  if (button_pressed(UP_PIN, &pressed_pointer[UP_POINT])) {
    clk_set->hour++;
    last_time_flash = millis();
    flash_on = true;
  }
  if (button_pressed(DOWN_PIN, &pressed_pointer[DOWN_POINT])) {
    clk_set->hour--;
    last_time_flash = millis();
    flash_on = true;
  }
  if (button_pressed(RIGHT_PIN, &pressed_pointer[LEFT_POINT])) {
    clk_set->minute++;
    last_time_flash = millis();
    flash_on = true;
  }
  if (button_pressed(LEFT_PIN, &pressed_pointer[RIGHT_POINT])) {
    clk_set->minute--;
    last_time_flash = millis();
    flash_on = true;
  }

  //-Cycles back when out of bounds
  if (clk_set->hour > HOUR_MAX) clk_set->hour = 0;
  if (clk_set->hour < 0) clk_set->hour = HOUR_MAX;
  if (clk_set->minute > MINUTE_MAX) clk_set->minute = 0;
  if (clk_set->minute < 0) clk_set->minute = MINUTE_MAX;

  //-Create flash
  if (timer(900, &last_time_flash)) flash_on = !flash_on;
  if (flash_on) color = RED;
  else color = BLACK;
}

