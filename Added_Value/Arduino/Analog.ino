
//--------------ANALOG--------------//
//---Manages analog clock display
//----------------------------------//

//--Draws image to screen
//--Does not use y[] like other modes
void draw_analog() {
  matrix.drawCircle(ANALOG_CENTER_X,7,7, PURPLE);
  boolean toRemove = timer(1000, &analog_last_second);
  write_hand(false, toRemove, AQUA);
  write_hand(true, toRemove, BLUE);
}

//--Draws hour and minute hands to screen
void write_hand(boolean isHour, boolean toRemove, int hand_color) {
  int hand_x, hand_y;
  int hr = clk.hour;
  int mn = clk.minute;
  if (toRemove) {
    hr--;
    mn--;
    hand_color = BLACK;
  }
  if (isHour) {
    hand_x = ANALOG_CENTER_X + cos((hr/12.0)*(2.0*pi) - pi/2.0)*4;
    hand_y = ANALOG_CENTER_Y + sin((hr/12.0)*(2.0*pi) - pi/2.0)*4;
  } else {
    hand_x = ANALOG_CENTER_X + cos((mn/60.0)*(2.0*pi) - pi/2.0)*6;
    hand_y = ANALOG_CENTER_Y + sin((mn/60.0)*(2.0*pi) - pi/2.0)*6;
  }
  matrix.drawLine(ANALOG_CENTER_X, ANALOG_CENTER_Y, hand_x, hand_y, hand_color);
}

