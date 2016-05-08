
//--------------MODE--------------//
//---Manages mode selection
//---Handles display/mode actions
//--------------------------------//

//--Allows selection of mode via roulette
void mode_select() {
  if (mode == 0) mode = TIME_SET;
  if (button_pressed(MODE_PIN, &pressed_pointer[MODE_POINT])) mode++;
  
  if (mode > 6 && mode != BONUS) mode = 1; //loops back to beginning of roulette
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
    set_clk(&alrm);
    draw();
    break;
  case TIME_SET:
    set_clk(&clk);
    draw();
    break;
  case ANALOG_PREP:
    clear_display();
    mode = ANALOG;
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

