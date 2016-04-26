
//-------------DIGITAL-------------//incomplete
//---Handles digital clock display
//---Includes mode for setting
//-----primary time
//---------------------------------//

const int HOUR_MAX = 24;
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
void set_clk(Time clk_set) {
  if (button_pressed(UP)) clk_set.hour++;
  if (button_pressed(DOWN)) clk_set.hour--;
  if (button_pressed(RIGHT)) clk_set.minute++;
  if (button_pressed(LEFT)) clk_set.minute--;

  if (clk.hour > HOUR_MAX) clk_set.hour = 1;
  if (clk.hour < 1) clk_set.hour = HOUR_MAX;
  if (clk.minute > MINUTE_MAX) clk_set.minute = 1;
  if (clk.minute < 0) clk_set.minute = MINUTE_MAX;
}

//--Sets display for time set mode
void disp_set_clk(Time clk_disp) {
  basic_digital(clk_disp);
  
  //-Create flash
  if (timer(900, &last_time_flash)) flash_on = !flash_on;
  if (flash_on) color = RED;
  else color = BLACK;
}

