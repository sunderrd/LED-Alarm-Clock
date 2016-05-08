
//-----------PONG GAME-----------//wiki
//---Manages display of the
//-----pong-style clock
//-------------------------------//

int left_score = 0, right_score = 0;
int ball_x = BALL_X_START, ball_y = BALL_Y_START;
int move_x = 1, move_y = 1;
int left_pad = 10, right_pad = 10;
int left_pad_move, right_pad_move;

//--Controls aspects of pong method
//--Should be called during pong mode
void pong_master() {
  color = YELLOW;
  
  if (timer(PONG_FRAME_RATE, &last_pong_time)) {
    move_ball();
    move_paddle();
  }

  //-Write everything
  add_pixel(ball_x, ball_y);
  filled_rect(1, 1, left_pad, 4);
  filled_rect(30, 1, right_pad, 4);
  write_score();
}

//--Keeps score up to date with clock when in other modes
void pong_background() {
  left_score = clk.hour;
  right_score = clk.minute;
}

//--Displays score/time
void write_score() {
  if (left_score < 10) {
    write_num(left_score, 11, 0, 1);
  } else {
    write_num(left_score/10, 7, 0, 1);
    write_num(left_score%10, 11, 0, 1);
  }
  
  if (right_score < 10) {
    write_num(right_score, 18, 0, 1);
  } else {
    write_num(right_score/10, 18, 0, 1);
    write_num(right_score%10, 22, 0, 1);
  }
}

//--Moves ball when called
void move_ball() {
  reset_display();
  
  //-Move ball one pixel
  ball_x += move_x;
  ball_y += move_y;

  //-Vertical bounce
  if (ball_y <= 5 || ball_y >= 15) move_y = -1*move_y;

  //-Bounce off paddle
  if (ball_x == 1 && ball_y >= left_pad && ball_y <= left_pad+3) {
    move_x = 1;
    ball_x += 2*move_x;
  }
  if (ball_x == 30 && ball_y >= right_pad && ball_y <= right_pad+3) {
    move_x = -1;
    ball_x += 2*move_x;
  }

  //-Respond when ball goes out of bounds
  if (ball_x < 0) {
    ball_x = BALL_X_START;
    ball_y = BALL_Y_START;
    move_x = 1;
    move_y = 1;
    right_score++;
  }
  if (ball_x > 31) {
    ball_x = BALL_X_START;
    ball_y = BALL_Y_START;
    move_x = 1;
    move_y = 1;
    left_score++;
  }

  //-Reset score when exceeds time maxes
  if (left_score > 23) left_score = 0;
  if (right_score > 59) right_score = 0;
}

//-Controls the movement of the paddle
void move_paddle() {
  
  //-Move left paddle
  if (move_x < 0) {
    if (clk.minute == right_score) {
      if (left_pad+1 > ball_y) left_pad_move = -1;
      if (left_pad+1 < ball_y) left_pad_move = 1;
    } else {
      if (ball_x == 15) {
        if (ball_y > 5 && ball_y < 13 && move_y < 0) {
          left_pad_move = -1;
        } else {
          left_pad_move = 1;
        }
      }
    }
    left_pad += left_pad_move;
  }
  
  //-Move right paddle
  if (move_x > 0) {
    if (clk.hour == left_score) {
      if (right_pad+1 > ball_y) right_pad_move = -1;
      if (right_pad+1 < ball_y) right_pad_move = 1;
    } else {
      if (ball_x == 16) {
        if (ball_y > 5 && ball_y < 13 && move_y < 0) {
          right_pad_move = -1;
        } else {
          right_pad_move = 1;
        }
      }
    }
    right_pad += right_pad_move;
  }

  //-Keep paddles in bounds
  if (left_pad < 5) left_pad = 5;
  if (left_pad > 12) left_pad = 12;
  if (right_pad < 5) right_pad = 5;
  if (right_pad > 12) right_pad = 12;
}

