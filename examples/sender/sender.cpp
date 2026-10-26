#include <Arduino.h>
#include "CanMessages.h"

#define CAN_TX_PIN GPIO_NUM_12
#define CAN_RX_PIN GPIO_NUM_11

CanManager can;
uint8_t compteur = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Initialisation de l'émetteur CAN...");

  // Initialisation du bus CAN
  if (can.init(CAN_RX_PIN, CAN_TX_PIN)) {
    Serial.println("CAN initialisé avec succès !");
  } else {
    Serial.println("Échec de l'initialisation du CAN.");
    while (1);
  }
}

void loop() {
  // Préparation de la trame CAN
  can_frame_t frame;
  frame.id = 0x123;    
  frame.length = 8;     
  frame.rtr = false;     
  
  frame.data[0] = 0xAA;
  frame.data[1] = 0xBB;
  frame.data[2] = 0xCC;
  frame.data[3] = 0xDD;
  frame.data[4] = 0xEE;
  frame.data[5] = 0xFF;
  frame.data[6] = 0x00;
  frame.data[7] = compteur;

  // Envoi du message
  can.send_can(frame);

  Serial.print("Message envoyé avec l'ID: 0x");
  Serial.print(frame.id, HEX);
  Serial.print(" | Compteur: ");
  Serial.println(compteur);

  compteur++;
  
  delay(1000);
}