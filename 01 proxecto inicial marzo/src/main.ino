#include <Arduino.h>
#include <TTN_esp32.h>


const char* devAddr = "260B510F"; // Change to TTN Device Address
const char* nwkSKey = "AEBC01BC0DF092F6BB2E9111964EACAB"; // Change to TTN Network Session Key
const char* appSKey = "CD8C3789C2BAE32E6E431D70D5CDE3E8"; // Change to TTN Application Session Key

TTN_esp32 ttn ;

void setup() {

  // put your setup code here, to run once:

  Serial.begin(115200);
  ttn.begin();
  Serial.println("Inicializando con ABP");
  ttn.personalize(devAddr, nwkSKey, appSKey);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Empezando");

  uint8_t myByte[] = {2, 3};

  Serial.println("Enviando 1 byte");
  ttn.sendBytes(myByte, 2);

  delay(5000);
}