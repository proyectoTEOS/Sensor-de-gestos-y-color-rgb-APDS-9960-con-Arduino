/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
*/

#include "Adafruit_APDS9960.h" //https://github.com/adafruit/Adafruit_APDS9960

const int intervalT = 1500;
unsigned long previousMillisT, currentMillisT;
boolean statusDelayT = true;
uint8_t gestureT;

Adafruit_APDS9960 gestureSensorT;

void setup() {
  Serial.begin(115200);
  if (!gestureSensorT.begin()) {
    Serial.println("No ha sido posible iniciar el sensor");
    delay(1000);
    while (1);
  }
  else
    Serial.println("Sensor iniciado");

  previousMillisT = millis();
  gestureSensorT.enableProximity(true);
  gestureSensorT.enableGesture(true);
}

void loop() {
  gestureT = gestureSensorT.readGesture();
  if (statusDelayT) {
    if (gestureT == APDS9960_DOWN) {
      Serial.println("Abajo");
      statusDelayT = false;
    }
    if (gestureT == APDS9960_UP) {
      Serial.println("Arriba");
      statusDelayT = false;
    }
    if (gestureT == APDS9960_LEFT) {
      Serial.println("Izquierda");
      statusDelayT = false;
    }
    if (gestureT == APDS9960_RIGHT) {
      Serial.println("Derecha");
      statusDelayT = false;
    }
  } else {
    currentMillisT = millis();
    if ((unsigned long)(currentMillisT - previousMillisT) >= intervalT) {
      previousMillisT = millis();
      statusDelayT = true;
    }
  }
}
