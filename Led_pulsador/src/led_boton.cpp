#include "Led_boton.h"

const int LEDOUT=12;
const int BOTON=13;
int val;

void ledSetup()
{
  pinMode(LEDOUT,OUTPUT);
  pinMode(BOTON,INPUT);
}


void ledLoop()
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