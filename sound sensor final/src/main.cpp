//credit du code https://gist.github.com/damiandawber/cc3c9c828aee2b85bddcc7754e59f080
//credit du code Mr Andre Roussel , fichier zip envoye pour le TMP36
/*
  Titre      : sound sensor avec l'arduino
  Auteur     : Anis Irsane
  Date       : 05/12/2022
  Description: le fonctionnement necessaire pour detecter le son , faire des traitement selon ces entrees puis les envoyes sur thingsboard
  Version    : 0.0.3
*/

#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

// Broche d'entree sortie 
const int ANALOG_PIN  = A0; 
const int LedRed   = 4;

const int LedGreen2    = 3 ; 
 
int AnalogValue       = 0; 

void setup() { 

  Serial.begin(9600);

  wifiConnect();       
  MQTTConnect();       

  pinMode(ANALOG_PIN, INPUT); 
  pinMode(LedGreen2, OUTPUT);
  pinMode(LedRed, OUTPUT);

}

void loop() {
  
  // Affectation valeur obtenue vers la variable 
  AnalogValue = analogRead(ANALOG_PIN);
  delay(2000);

  // Condition pour faire fonctionner les LED 
  if (AnalogValue > 5 ) {
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen2, LOW);

  }
  else {
    digitalWrite(LedGreen2, HIGH);
    digitalWrite(LedRed, LOW);

  }

  //Affichage de la valeur obtenue
  Serial.print("La valeur obtene par la broche analogue est ");
  Serial.println(AnalogValue);
  
  // Envoi de la valeur obtenue vers le serveur ThingsBoard 
  appendPayload("Intensite de Son", AnalogValue);
  sendPayload();  

  delay(40);
}
