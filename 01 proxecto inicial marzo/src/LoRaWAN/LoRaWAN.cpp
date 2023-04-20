#include "LoRaWAN.h"
#include <TTN_esp32.h>
//#include "../GPS/GPS.h"

const char* devAddr = "260B510F"; // Change to TTN Device Address
const char* nwkSKey = "AEBC01BC0DF092F6BB2E9111964EACAB"; // Change to TTN Network Session Key
const char* appSKey = "CD8C3789C2BAE32E6E431D70D5CDE3E8"; // Change to TTN Application Session Key

TTN_esp32 ttn ;


void LoRaWAN_setup() {
    Serial.println("LoRaWAN: Inicializando con ABP");
    ttn.begin();
    ttn.personalize(devAddr, nwkSKey, appSKey);
}

void LoRaWAN_loop() {

}

bool LoRaWAN_enviarGPS(uint8_t* gpsPos) {
    Serial.println("Enviando 1 byte");
    ttn.sendBytes(gpsPos, 1);

    return false;
}