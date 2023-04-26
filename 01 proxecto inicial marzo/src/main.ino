#include <Arduino.h>
#include "LoRaWAN/LoRaWAN.h"
#include "gps/gps.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  LoRaWAN_setup();
  setupGPS();

  Serial.println("Inicialization sequence complete...");
}

unsigned long lastLoraMillis = 0;
void loop() {
  uint8_t myByte[9];

    smartGPSdelay(5000);
  if (checkGPSFix())
  {
    buildGPSpacket(myByte);
    Serial.println("Enviando paquete LoRaWAN");
    ttn.sendBytes(myByte, sizeof(myByte));
  }
  printGPSdata();


  if (millis() - lastLoraMillis > 5000 ) {
    lastLoraMillis = millis();
    LoRaWAN_enviarGPS(myByte);
  }
  
  //LoRaWAN_loop();

}