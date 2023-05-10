#include <Arduino.h>
#include "LoRaWAN/LoRaWAN.h"
#include "gps/gps.h"
#include "OLED/oled.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  LoRaWAN_setup();
  setupGPS();
  setupOLED();
	ledSetup();

  Serial.println("Inicialization sequence complete...");
}

//unsigned long lastLoraMillis = 0;
void loop() {
  uint8_t gpsPos[9];

  smartGPSdelay(5000);
  if (checkGPSFix())
  {
    buildGPSpacket(gpsPos);
    Serial.println("Enviando paquete LoRaWAN");
    LoRaWAN_enviarGPS(gpsPos);
  }
  printGPSdata();

/*
  if (millis() - lastLoraMillis > 5000 ) {
    lastLoraMillis = millis();
    LoRaWAN_enviarGPS(gpsPos);
  }
  */
  //LoRaWAN_loop();
 	ledLoop();

}