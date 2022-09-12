
#include "Keyboard.h"

bool lastState = false;

void setup() {
  pinMode(A0, INPUT_PULLUP);
  
  Keyboard.begin();
  delay(2000);
}

void loop() {
    delay(20);
    
    bool currentState = digitalRead(A0);

    if(currentState != lastState) {
      if(currentState) {
        Keyboard.print("i");
      } else {
        Keyboard.press(KEY_ESC);
        delay(50);
        Keyboard.release(KEY_ESC);
      }
    }
    
    lastState = currentState;
}
