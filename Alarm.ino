
//-------------ALARM-------------//incomplete
//---Handles time set and
//-----execution of alarm
//-------------------------------//


//--Makes noise, etc for alarm
//--Needs the "etc"
void alarm() {
  boolean sound_on;
  if (timer(500, &last_sound_time)) sound_on = !sound_on;
  if (sound_on) {
    tone(BUZZ, 30000);
  } else {
    noTone(BUZZ);
  }
}

