// archivo principal: main.ino
#include <Arduino.h>
#include "Led_boton.h"


void setup() {
  // Inicialización de los módulos
  ledSetup();
}

void loop() {
  // Llamada a los módulos
  ledLoop();
}