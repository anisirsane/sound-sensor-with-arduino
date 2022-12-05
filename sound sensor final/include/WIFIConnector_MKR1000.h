/*
  Titre      : WIFIConnector_MKR1000.h
  Auteur     : André Roussel
  Date       : 03/11/2021
  Description: Fonctions nécessaire pour branché un Arduino MKR1000 a un réseau WIFI
  Droits     : Reproduction permise pour usage pédagogique
  Version    : 0.0.1
*/


#include "Secrets.h"
#include <SPI.h>
#include <wifi101.h>
#include "wifiStatus.h"



const char SSID[] = WIFI_SECRET_SSID; // WiFI ssid provenant du fichier Secrets.h
const char PASS[] = WIFI_SECRET_PASS; //WiFI mot de passe provenant du fichier Secrets.h

int status = WL_IDLE_STATUS;          // Statut de la radio WIFI



WiFiClient ClientWIFI;                //Objets représantant un client se branchant a un réseau WIFI


/*
Fonction de connectivité a un réseau WIFI
*/

void wifiConnect()
{
  
  // Boucle de branchement au réseau WIFI.  Essaie de branchement a tout les 10 secondes jusqu'a réussite
  while (status != WL_CONNECTED) 
  {
    Serial.print("Tentative de branchement au réseau: ");
    Serial.println(SSID);
    status = WiFi.begin(SSID, PASS);
    Serial.println(status);

    
    delay(10000);  // Délai de 10 secondes entre les tentatives de connexion
  }

  //Sortie de la boucle, alors branché au réseau SSID
  Serial.print("Maintenant branché au réseau WIFI ");
  Serial.println(SSID);

  //Impression de l'information de connexion
  printCurrentNet();
  printWifiData();

}
