
//-----------------GRAPHICS-----------------//
//---Functions involving the display that
//---are not included in the library
//------------------------------------------//


//--Draws image based on x[] globals--//
void draw() {
  for (int i=0; i<32; i++) {
    for (int j=0; j<16; j++) {
      //Serial.println(x[15]);
      if ((y[i] & (1<<j)) != 0) {
        
        matrix.drawPixel(i, j, color);
      } else {
        //matrix.drawPixel(i, j, BLACK);
      }
    }
  }
}
//--End--//

//--Resets values of graphics globals to 0--//
void reset_display() {
  for (int i=0; i<16; i++) {
    y[i] = 0;
  }
  color = BLACK;
}
//--End--//

//--Clears screen and turns LEDs off--//
void clear_display() {
  reset_display();
  draw();
}
//--End--//

//--Adds number to screen at given position--//
//--Position given as top left coordinate
void write_num(int num, int pos_x, int pos_y) {
  for (int i=0; i<5; i++) {
    y[pos_x + i] |= (nums[num].y[i] << (pos_y));
  }
}
//--End--//
