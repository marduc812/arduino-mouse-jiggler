#include <Mouse.h>

int ledPin = 13;

int top = 0;
int right = 0;
int randomMoveRange = 500;
int maxMoveRange = 600;
int randomDelayTimer = 20000;

void setup() {
  Mouse.begin();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  smoothMove(newRight(), newTop());
  notifyActivity();
}

void smoothMove(int distanceX, int distanceY) {
  if (distanceX > 0) {
    for (int j = 0; j < distanceX; j++) {
    Mouse.move(1, 0, 0);
    delay(1);
    }
  } else {
    for (int j = 0; j > distanceX; j--) {
    Mouse.move(-1, 0, 0);
    delay(1);
    }
  }

  if (distanceY > 0) {
    for (int j = 0; j < distanceY; j++) {
    Mouse.move(0, 1, 0);
    delay(1);
    }
  } else {
    for (int j = 0; j > distanceY; j--) {
    Mouse.move(0, -1, 0);
    delay(1);
    }
  }
}


int newTop() {
  int moveTop = 0;
  int randTop = random(randomMoveRange);
  
  
  if (top >= maxMoveRange) {
    moveTop = 0 - randTop;
  } else if ( top <= (0 - maxMoveRange)) {
    moveTop = 0 +  randTop;
  } else {
    int luck = random(2);
    if (luck == 1)
    {
      moveTop = 0 -  randTop;
    } else {
      moveTop = 0 +  randTop;
    }
  }
  top+= moveTop;
  return moveTop;
}

int newRight() {
  int moveRight = 0;
  int randRight = random(randomMoveRange);
  
  
  if (right >= maxMoveRange) {
    moveRight = 0 - randRight;
  } else if ( top <= (0 - maxMoveRange)) {
    moveRight = 0 +  randRight;
  } else {
    int luck = random(2);
    if (luck == 1)
    {
      moveRight = 0 -  randRight;
    } else {
      moveRight = 0 +  randRight;
    }
  }
  top+= moveRight;
  return moveRight;
}

void notifyActivity() {
  digitalWrite(ledPin, HIGH); 
  int randomDelay = random(randomDelayTimer);
  delay(randomDelay);            
  digitalWrite(ledPin, LOW);  
  delay(1000); 
}