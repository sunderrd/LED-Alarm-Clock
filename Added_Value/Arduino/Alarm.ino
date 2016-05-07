
//-------------ALARM-------------//incomplete
//---Handles time set and
//-----execution of alarm
//-------------------------------//

int clk_temp, alrm_temp;
int snooze_time;

//--Makes noise, etc for alarm
//--Needs the "etc"
void alarm_sound() {
  if (timer(500, &last_sound_time)) sound_on = !sound_on;
  if (sound_on) {
    tone(BUZZ, 1000);
  } else {
    noTone(BUZZ);
  }
}

void check_alarm() {
  if (button_pressed(ALM_ON_PIN, &pressed_pointer[ALM_ON_POINT])) alarm_on = !alarm_on;
  clk_temp = clk.hour*60 + clk.minute;
  alrm_temp = alrm.hour*60 + alrm.minute + snooze_time;
  if (alarm_on) {
    if (clk_temp == alrm_temp) {
      alarm_sound();
      if (button_pressed(SNOOZE_PIN, &pressed_pointer[SNOOZE_POINT])) {
        snooze_time += 9;
      }
    }
  } else {
    noTone(BUZZ);
    snooze_time = 0;
  }
}

