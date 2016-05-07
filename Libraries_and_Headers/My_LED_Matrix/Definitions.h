//  Definitions.h
//  Created by Ryan Sunderhaus

#ifndef Definitions_h
#define Definitions_h

//--Pins
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
#define BUZZ 10

#define UP_PIN      0
#define LEFT_PIN    11
#define DOWN_PIN    1
#define RIGHT_PIN   13
#define ALM_ON_PIN  A4
#define MODE_PIN    12
#define SNOOZE_PIN  A5

//--Time struct; hours in 24 hr format
typedef struct {
    int hour, minute, second, ms;
} Time;

//--Modes
#define CLASSIC     1
#define PONG        4
#define TIME_SET    5
#define ALARM_SET   6
#define ANALOG_PREP 2
#define ANALOG      3
#define BONUS       10 //secret mode if special buttons pressed

//--Pointer array values
#define UP_POINT      1
#define LEFT_POINT    5
#define DOWN_POINT    0
#define RIGHT_POINT   6
#define ALM_ON_POINT  4
#define MODE_POINT    2
#define SNOOZE_POINT  3

//--Constants
const float pi = 3.14159265359;
const int DEBOUNCE_DELAY = 50;
const int ANALOG_CENTER_X = 15;
const int ANALOG_CENTER_Y = 7;

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

//--Colors
const int BLACK = matrix.Color333(0,0,0);
const int YELLOW = matrix.Color333(1,1,0);
const int RED = matrix.Color333(1,0,0);
const int BLUE = matrix.Color333(0,0,1);
const int GREEN = matrix.Color333(0,1,0);
const int AQUA = matrix.Color333(0,1,1);
const int WHITE = matrix.Color333(1,1,1);
const int PURPLE = matrix.Color333(1,0,1);

//---Code definining values used to draw numbers---//
typedef struct {
    int y[5];
} Number;

Number chars[10];

void chars_setup() { //numbers appear rotated due to bitshift process
    chars[0].y[0] = 0b11111;
    chars[0].y[1] = 0b10001;
    chars[0].y[2] = 0b11111;
    
    chars[1].y[0] = 0b00000;
    chars[1].y[1] = 0b00000;
    chars[1].y[2] = 0b11111;
    
    chars[2].y[0] = 0b11101;
    chars[2].y[1] = 0b10101;
    chars[2].y[2] = 0b10111;
    
    chars[3].y[0] = 0b10101;
    chars[3].y[1] = 0b10101;
    chars[3].y[2] = 0b11111;
    
    chars[4].y[0] = 0b00111;
    chars[4].y[1] = 0b00100;
    chars[4].y[2] = 0b11111;
    
    chars[5].y[0] = 0b10111;
    chars[5].y[1] = 0b10101;
    chars[5].y[2] = 0b11101;
    
    chars[6].y[0] = 0b11111;
    chars[6].y[1] = 0b10101;
    chars[6].y[2] = 0b11101;
    
    chars[7].y[0] = 0b00001;
    chars[7].y[1] = 0b00001;
    chars[7].y[2] = 0b11111;
    
    chars[8].y[0] = 0b11111;
    chars[8].y[1] = 0b10101;
    chars[8].y[2] = 0b11111;
    
    chars[9].y[0] = 0b10111;
    chars[9].y[1] = 0b10101;
    chars[9].y[2] = 0b11111;
}
//-----------END-------------//

//---
int circ[16];

void circ_setup() {
    circ[0]  = 0b0000011111100000;
    circ[1]  = 0b0001100000011000;
    circ[2]  = 0b0010000000000100;
    circ[3]  = 0b0100000000000010;
    circ[4]  = 0b0100000000000010;
    circ[5]  = 0b1000000000000001;
    circ[6]  = 0b1000000000000001;
    circ[7]  = 0b1000000000000001;
    circ[8]  = 0b1000000000000001;
    circ[9]  = 0b1000000000000001;
    circ[10] = 0b1000000000000001;
    circ[11] = 0b0100000000000010;
    circ[12] = 0b0100000000000010;
    circ[13] = 0b0010000000000100;
    circ[14] = 0b0001100000011000;
    circ[15] = 0b0000011111100000;
}
//---END

#endif /* Definitions_h */
