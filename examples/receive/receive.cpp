#include <Arduino.h>
#include "CanMessages.h"

#define CAN_TX_PIN GPIO_NUM_12
#define CAN_RX_PIN GPIO_NUM_11

CanManager can;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Initialisation du sniffer CAN...");

  // Initialisation du bus CAN
  if (can.init(CAN_RX_PIN, CAN_TX_PIN)) {
    Serial.println("CAN initialisé avec succès !");
  } else {
    Serial.println("Échec de l'initialisation du CAN.");
    while (1);
  }
}

void loop() {
  can_frame_t frame;
  
  if (can.receive_can(&frame)) {
    Serial.print("ID: 0x");
    Serial.print(frame.id, HEX);
    
    if (frame.rtr) {
      Serial.println(" [RTR]");
    } else {
      Serial.print(" | DLC: ");
      Serial.print(frame.length);
      Serial.print(" | Data: ");
      
      for (uint8_t i = 0; i < frame.length; i++) {
        if (frame.data[i] < 0x10) {
          Serial.print("0");
        }
        Serial.print(frame.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}