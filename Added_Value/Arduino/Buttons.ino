
//--------------BUTTONS--------------//incomplete?
//---Manages button presses for both
//-----analog and digital pins
//-----------------------------------//


#define ANALOG_MAX 200

//--Creates universal button read function
//----for both analog and digital pins
boolean button_pressed(int pin, boolean *button_on) {
  if (read_button(pin)) *button_on = true;
  if (*button_on && !read_button(pin)) {
    *button_on = false;
    return true;
  } else return false;
}

boolean debounce(int pin) {
  boolean pressed = false;
  if (read_button(pin) && timer(DEBOUNCE_DELAY, &last_debounce_time)) {
    pressed = true;
  } else {
    pressed = false;
  }
  return pressed;
}

//--Allows for digital read of analog input pin
boolean read_button(int pin) {
  if (pin == ALM_ON_PIN || pin == SNOOZE_PIN) return (analogRead(pin) > ANALOG_MAX);
  else return digitalRead(pin);
}


