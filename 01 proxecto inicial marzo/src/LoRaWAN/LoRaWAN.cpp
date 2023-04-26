#include "LoRaWAN.h"
#include <TTN_esp32.h>
//#include "../GPS/GPS.h"

const char* devAddr = "260B6392"; // Change to TTN Device Address
const char* nwkSKey = "9ABBED8C31B62ECC7397D9C5076738D9"; // Change to TTN Network Session Key
const char* appSKey = "076F933D686CC67C8DD45378C9AAC910"; // Change to TTN Application Session Key

TTN_esp32 ttn ;


void LoRaWAN_setup() {
    Serial.println("LoRaWAN: Inicializando con ABP");
    ttn.begin();
    ttn.personalize(devAddr, nwkSKey, appSKey);
    ttn.setDataRate(5); //configura DataRate a 5 (SF7)
    ttn.showStatus();

}

void LoRaWAN_loop() {

}

bool LoRaWAN_enviarGPS(uint8_t* gpsPos) {
    Serial.println("Enviando 1 byte");
    ttn.sendBytes(gpsPos, sizeof(gpsPos));

    return false;
}