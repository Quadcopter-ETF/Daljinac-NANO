#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);
const int bUp= 6;
const int bDn=1;
const int bF=4;
const int bB=3;
const int bL=5;
const int bR=2;   
const uint64_t rxAddr[6] = {1};
int mUp = 1;
int mDn= 2;
int mF= 3;
int mB= 4;
int mL= 5;
int mR= 6;
// Variables will change:
int buttonStateUp,buttonStateDn,buttonStateF,buttonStateB,buttonStateL,buttonStateR;             // the current reading from the input pin
int lastButtonStateUp,lastButtonStateDn,lastButtonStateF,lastButtonStateB,lastButtonStateL,lastButtonStateR = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

bool debounce(const int pin ,int last, int reading, int state)
{
  if (reading!= last) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != state) {
      state = reading;
      // only toggle the LED if the new button state is HIGH
    }
  }
  last = reading;
  if (state == HIGH) {
       return true;
      }
  else return false;
}





void setup() {
  pinMode(bUp, INPUT);
  pinMode(bDn, INPUT);
  pinMode(bF, INPUT);
  pinMode(bB, INPUT);
  pinMode(bL, INPUT);
  pinMode(bR, INPUT);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr[0]);
  radio.stopListening();
}
void loop() {
  // Up
  int readingUp = digitalRead(bUp);
  if (debounce(bUp,lastButtonStateUp,readingUp,buttonStateUp)) {
       radio.write(&mUp, sizeof(mUp));
      }  
   // Down
  int readingDn = digitalRead(bDn);

      if (debounce(bDn,lastButtonStateDn,readingDn,buttonStateDn)) {
       radio.write(&mDn, sizeof(mDn));
      }  
   // Forward
  int readingF = digitalRead(bF);
  
      if (debounce(bF,lastButtonStateF,readingF,buttonStateF)) {
       radio.write(&mF, sizeof(mF));
      }  
  
   // Backward
  int readingB = digitalRead(bB);
  
      if (debounce(bB,lastButtonStateB,readingB,buttonStateB)) {
       radio.write(&mB, sizeof(mB));
      }  
  
   // Left
  int readingL = digitalRead(bL);
  
      if (debounce(bL,lastButtonStateL,readingL,buttonStateL)) {
       radio.write(&mL, sizeof(mL));
      } 
  
   // Right
  int readingR = digitalRead(bR);
  
      if (debounce(bR,lastButtonStateR,readingR,buttonStateR)) {
       radio.write(&mR, sizeof(mR));
      }  
  
}
