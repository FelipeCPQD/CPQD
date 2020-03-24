/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
#define LED_AMARELO 22
#define BOTAO 26
#define BOTAO_INC 30
#define LED 9 
#define DUTY 255

float incremento = 0;
float porcent = 0;

void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(9600);

  pinMode(LED_AMARELO, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(BOTAO_INC, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int estado = digitalRead(BOTAO);
  

  if(estado == 0){
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_AMARELO, HIGH);
  }else
  {
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_AMARELO, LOW);
  }

  int estadoInc = digitalRead(BOTAO_INC);
  if (estadoInc == 0)
  {
    if (incremento >= 0 && incremento < 1)
    {
      incremento = incremento + 0.25;
      delay(300);
    }else
    {
      incremento = 0;
      delay(300);
    }
    Serial.println(incremento);    
  }

  porcent = incremento*DUTY;
  analogWrite(LED, porcent);
  
}