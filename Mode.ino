
//--------------MODE--------------//incomplete
//---Manages mode selection
//---Handles display/mode actions
//--------------------------------//

const int BONUS_COUNT_MAX = 1000;

//--Allows selection of mode via roulette
void mode_select() {
  if (mode == 0) mode = CLASSIC;
  if (button_pressed(MODE)) {
    mode++;
  }
  if (mode > 5 && mode != BONUS) mode = 1; //loops back to beginning of roulette

  //Implements bonus mode
  //if (read_analog(SELECT) && read_analog(SNOOZE)) bonus_count++;
  //if (bonus_count > BONUS_COUNT_MAX) mode = BONUS;
}

//--Executes given functions for each mode
//--Calls display write function to modify y[]
//--Draws new display
void execute_mode() {
  if (mode != PONG) pong_background();
  
  switch (mode) {
  case CLASSIC:
    basic_digital(clk);
    draw();
    break;
  case PONG:
    pong_master();
    draw();
    break;
  case ALARM_SET:
    set_clk(alarm);
    disp_set_clk(alarm);
    draw();
    break;
  case TIME_SET:
    set_clk(clk);
    disp_set_clk(clk);
    draw();
    break;
  case ANALOG:
    draw_analog();
    break;
  case BONUS:
    filled_rect(0, 32, 0, 16);
    draw();
    break;
  default:
    mode = CLASSIC;
  }
  reset_display();
}

