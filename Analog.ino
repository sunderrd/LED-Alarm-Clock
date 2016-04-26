
//--------------ANALOG--------------//incomplete
//---Manages analog clock display
//----------------------------------//


//--
void draw_analog() {
  //matrix.fillCircle(7,7,7, BLACK);
  matrix.drawCircle(7,7,7, PURPLE);
  boolean toRemove = timer(1000, &analog_last_second);
  write_hand(false, toRemove, AQUA);
  write_hand(true, toRemove, BLUE);
}

//--
void write_circle() {
  for (int i=0; i<16; i++) {
    y[i] |= circ[i];
  }
}

//--
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
    hand_x = 7 + cos((hr/12.0)*(2.0*pi) - pi/2.0)*4;
    hand_y = 7 + sin((hr/12.0)*(2.0*pi) - pi/2.0)*4;
  } else {
    hand_x = 7 + cos((mn/60.0)*(2.0*pi) - pi/2.0)*6;
    hand_y = 7 + sin((mn/60.0)*(2.0*pi) - pi/2.0)*6;
  }
  matrix.drawLine(7,7, hand_x, hand_y, hand_color);
}

