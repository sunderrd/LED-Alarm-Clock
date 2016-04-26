
//--------------BUTTONS--------------//incomplete debounce?
//---Manages button presses for both
//-----analog and digital pins
//-----------------------------------//


#define ANALOG_MAX 200

//--Creates universal button read function
//----for both analog and digital pins
boolean button_pressed(int pin) {
  boolean pressed = false;
  if (pin == SELECT || pin == SNOOZE) {
    while (read_analog(pin)) pressed = true;
  } else {
    //while (digitalRead(pin) == HIGH) pressed = true;
  }
  return pressed;
}

//--Allows for digital read of analog input pin
boolean read_analog(int pin) {
  if (analogRead(pin) > ANALOG_MAX) return true;
  else return false;
}

