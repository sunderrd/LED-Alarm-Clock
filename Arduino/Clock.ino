
//------------CLOCK------------//done?
//---Controls clock functions
//---Manages clock variables
//---Includes timer functions
//-----------------------------//


//--Updates time values of clk
void update_time() {
  unsigned long temp = millis();
  clk.ms = temp - last_time;
  
  if (clk.ms >= 1000) {
    clk.second++;
    clk.ms -= 1000;
    last_time = temp;
  }

  if (clk.second >= 60) {
    clk.minute++;
    clk.second -= 60;
  }

  if (clk.minute >= 60) {
    clk.hour++;
    clk.minute -= 60;
  }

  if (clk.hour >= 24) {
    clk.hour -= 24;
  }
}

//--Resets second count
void reset_seconds() {
  clk.second = 0;
}

//--Returns true if time_length has passed since last true value returned
boolean timer(int timer_length, unsigned long *last_value) {
  boolean out = false;
  unsigned long temp = millis();
  if (temp >= *last_value + timer_length) {
    *last_value = temp;
    out = true;
  }
  last_value = NULL;
  return out;
}

