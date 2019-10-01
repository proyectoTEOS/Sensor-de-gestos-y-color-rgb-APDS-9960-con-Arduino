# Sensor de gestos y color rgb APDS-9960 con Arduino
En esta entrada usaremos el sensor de gestos para detectar 4 movimientos con la ayuda de nuestro Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Contar con la librería [Adafruit APDS9960](https://github.com/adafruit/Adafruit_APDS9960)
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/Sensor-de-gestos-y-color-rgb-APDS-9960-con-Arduino/blob/master/Sensor-de-gestos-y-color-rgb-APDS-9960-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
*/

#include "Adafruit_APDS9960.h" //https://github.com/adafruit/Adafruit_APDS9960

const int intervalT = 1500;
unsigned long previousMillisT, currentMillisT;
bool statusDelayT = true;
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
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Sensor-de-gestos-y-color-rgb-APDS-9960-con-Arduino/blob/master/sensor-de-gestos-y-color-rgb-apds-9960-con-arduino-5.jpg)
