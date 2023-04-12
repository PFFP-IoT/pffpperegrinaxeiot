#include <Arduino.h>
#include "LoRaWAN/LoRaWAN.h"
//#include "GSP/GSP.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  LoRaWAN_setup();

  Serial.println("Inicialization sequence complete...");
}

unsigned long lastLoraMillis = 0;
void loop() {
  uint8_t myByte[] = {2, 3};

  if (millis() - lastLoraMillis > 5000 ) {
    lastLoraMillis = millis();
    LoRaWAN_enviarGPS(myByte);
  }
  
  //LoRaWAN_loop();

}