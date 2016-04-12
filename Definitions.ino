
//--Colors--//
const int BLACK = matrix.Color333(0,0,0);
//--End--//

//--Code definining values used to draw numbers--//
struct Number {
  int y[5];
};

Number nums[10];

//numbers appear rotated due to bitshift process
void nums_setup() {
nums[0].y[0] = 0b11111;
nums[0].y[1] = 0b10001;
nums[0].y[2] = 0b11111;

nums[1].y[0] = 0b00000;
nums[1].y[1] = 0b11111;
nums[1].y[2] = 0b00000;

nums[2].y[0] = 0b11101;
nums[2].y[1] = 0b10101;
nums[2].y[2] = 0b10111;

nums[3].y[0] = 0b10101;
nums[3].y[1] = 0b10101;
nums[3].y[2] = 0b11111;

nums[4].y[0] = 0b00111;
nums[4].y[1] = 0b00100;
nums[4].y[2] = 0b11111;

nums[5].y[0] = 0b10111;
nums[5].y[1] = 0b10101;
nums[5].y[2] = 0b11101;

nums[6].y[0] = 0b11111;
nums[6].y[1] = 0b10101;
nums[6].y[2] = 0b11101;

nums[7].y[0] = 0b00001;
nums[7].y[1] = 0b00001;
nums[7].y[2] = 0b11111;

nums[8].y[0] = 0b11111;
nums[8].y[1] = 0b10101;
nums[8].y[2] = 0b11111;

nums[9].y[0] = 0b10111;
nums[9].y[1] = 0b10101;
nums[9].y[2] = 0b11111;
}
//-----------END-------------//
