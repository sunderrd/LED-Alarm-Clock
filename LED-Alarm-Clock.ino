//TO DO:
//-Timer/clock
//-Display modes
//-Buttons; needed helper fucntions (shift register reading?)
//-'Set' modes
//-Tidy up

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

//--GLOBALS--//
long y[32];
int color;
//-----------//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix.begin();
  
  nums_setup();

  //temp
  color = matrix.Color333(1,0,0);
  for (int i=0; i<5; i++) {
    write_num(i, i*4, 0);
  }
  for (int i=5; i<10; i++) {
    write_num(i, i*4-16, 7);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  draw();
}
