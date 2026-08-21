#include "CanMessages.h"

/*
void setup() {
}


void loop() {
}
*/

CanManager can;

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 2000;

uint8_t vitesseMoteur = 50;

void setup() {
    Serial.begin(115200);
    pinMode(10, OUTPUT);
    #ifdef ARDUINO_ARCH_ESP32
      can.init(GPIO_NUM_11, GPIO_NUM_12);
    #endif
    #ifdef ARDUINO_ARCH_STM32
      can.init();
    #endif
    
    Serial.println("Émetteur CAN initialisé");
}

void loop() {
    can.update();

    if (Serial.available() > 0) {
        int input = Serial.parseInt();
        
        if (input >= 0 && input <= 255) {
            vitesseMoteur = input;
            Serial.printf("\n>>> Nouvelle vitesse enregistree : %d <<<\n\n", vitesseMoteur);
        }
        

        while(Serial.available() > 0) {
            Serial.read();
        }
    }

    if (millis() - lastSendTime >= sendInterval) {
      lastSendTime = millis();

      MOTEUR msg;
      msg.motor_id = motor_id_t::RIGHT;
      msg.etat = true;
      msg.speed = vitesseMoteur;
      can.send(msg);
      
      Serial.print("Message CAN envoye -> ");
      Serial.print(" | Vitesse : ");
      Serial.println(vitesseMoteur);
    }
}