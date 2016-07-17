#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);
const int bUp= 2;
const int bDn=3;
const int bF=4;
const int bB=5;
const int bL=6;
const int bR=9;   
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


void setup() {
  Serial.begin(9600);
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
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(120);
}
void loop() {
  // Up
  int readingUp = digitalRead(bUp);
  if (readingUp != lastButtonStateUp) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingUp != buttonStateUp) {
      buttonStateUp = readingUp;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateUp == HIGH) {
       radio.write(&mUp, sizeof(mUp));
       Serial.println(mUp);
      }
    }
  }
  lastButtonStateUp = readingUp;
  
   // Down
  int readingDn = digitalRead(bDn);
  if (readingDn != lastButtonStateDn) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingDn != buttonStateDn) {
      buttonStateDn = readingDn;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateDn == HIGH) {
       radio.write(&mDn, sizeof(mDn));
       Serial.println(mDn);
      }
    }
  }
  lastButtonStateDn = readingDn;
  
   // Forward
  int readingF = digitalRead(bF);
  if (readingF != lastButtonStateF) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingF != buttonStateF) {
      buttonStateF = readingF;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateF == HIGH) {
       radio.write(&mF, sizeof(mF));
       Serial.println(mF);
      }
    }
  }
  lastButtonStateF = readingF;
  
   // Backward
  int readingB = digitalRead(bB);
  if (readingB != lastButtonStateB) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingB != buttonStateB) {
      buttonStateB = readingB;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateB == HIGH) {
       radio.write(&mB, sizeof(mB));
       Serial.println(mB);
      }
    }
  }
  lastButtonStateB = readingB;  
   // Left
  int readingL = digitalRead(bL);
  if (readingL != lastButtonStateL) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingL != buttonStateL) {
      buttonStateL = readingL;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateL == HIGH) {
       radio.write(&mL, sizeof(mL));
       Serial.println(mL);
      }
    }
  }
  lastButtonStateL = readingL;
   // Right
  int readingR = digitalRead(bR);
  if (readingR != lastButtonStateR) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (readingR != buttonStateR) {
      buttonStateR = readingR;
      // only toggle the LED if the new button state is HIGH
      if (buttonStateR == HIGH) {
       radio.write(&mR, sizeof(mR));
       Serial.println(mR);
      }
    }
  }
  lastButtonStateR = readingR;
}
