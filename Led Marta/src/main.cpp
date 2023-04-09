#include <Arduino.h>

const int LEDOUT=4;
const int BOTON=2;
int val;

void setup()
{
  pinMode(LEDOUT,OUTPUT);
  pinMode(BOTON,INPUT);
}


void loop()
{
  val=digitalRead(BOTON);
  if  (val==HIGH)     //pulsador levantado
  {
  digitalWrite(LEDOUT,LOW); 
  }
  else                // pulsado
  { digitalWrite(LEDOUT,HIGH);
  }
}