#include "CanMessages.h"

void setup() {
}


void loop() {
}

/*
CanManager can;

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 2000;

bool etatMoteur = false;

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

    if (millis() - lastSendTime >= sendInterval) {
      lastSendTime = millis();
      etatMoteur = !etatMoteur;

      MOTEUR moteurMsg;
      moteurMsg.etat = etatMoteur;
      Serial.println("Message envoyé");
      Serial.println(etatMoteur ? "Marche (1)" : "Arrêt (0)");
    }
}
*/