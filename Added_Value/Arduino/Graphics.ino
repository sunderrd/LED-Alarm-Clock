
//-----------------GRAPHICS-----------------//
//---Functions involving the display that
//-----are not included in the library
//------------------------------------------//

//--Draws image based on y[] globals
void draw() {
  for (int i=0; i<32; i++) {
    for (int j=0; j<16; j++) {
      //Serial.println(x[15]);
      if ((y[i] & (1<<j)) != 0) {
        matrix.drawPixel(i, j, color);
      } else {
        matrix.drawPixel(i, j, BLACK);
      }
    }
  }
}

//--Resets values of graphics globals to 0
void reset_display() {
  for (int i=0; i<32; i++) {
    y[i] = 0;
  }
}

//--Clears screen and turns LEDs off
void clear_display() {
  for (int i=0; i<32; i++) {
    y[i] = 65535;
  }
  color = BLACK;
  draw();
  reset_display();
}

//--Adds number to screen at given position
//--Position given as top left coordinate
//--Size given as 1 or 2
void write_num(int num, int pos_x, int pos_y, byte num_size) {
  if (num < 10 && num >= 0) {
    for (int i=0; i<3*num_size; i++) {
      for (int j=0; j<5*num_size; j++) {
        if (chars[num].y[i/num_size] & (1<<(j/num_size)))   y[pos_x + i] |= (1 << (pos_y+j));
      }
    }
  }
}

//--Adds single pixel to global array
void add_pixel(int add_x, int add_y) {
  if (add_x < 32 && add_x >= 0) {
    y[add_x] |= (1 << add_y);
  }
}

//--Adds filled rectangle to global array
void filled_rect(int left_x, int size_x, int top_y, int size_y) {
  for (int i=left_x; i<(left_x+size_x); i++) {
    for (int j=top_y; j<(top_y+size_y); j++) {
      add_pixel(i, j);
    }
  }
}

