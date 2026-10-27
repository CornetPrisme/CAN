#include "CanManager.h"

#ifdef ARDUINO_ARCH_ESP32
#define CAN_TX_PIN GPIO_NUM_12
#define CAN_RX_PIN GPIO_NUM_11
#endif

CanManager can;

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("Start");

    // Initialisation
    #ifdef ARDUINO_ARCH_ESP32
      can.init(CAN_RX_PIN, CAN_TX_PIN);
    #endif
    
    #ifdef ARDUINO_ARCH_STM32
      can.init();
    #endif
}

void loop() {
    can_frame_t trame_brute;
    if (can.receive_can(&trame_brute)) {
        Serial.print("ID: 0x");
        Serial.print(trame_brute.id, HEX);
        Serial.print(" | RTR: ");
        Serial.print(trame_brute.rtr);
        Serial.print(" | Taille: ");
        Serial.print(trame_brute.length);
        Serial.print(" | Données: ");
        for (uint8_t i = 0; i < trame_brute.length; i++) {
            Serial.print("0x");
            if (trame_brute.data[i] < 0x10) Serial.print("0");
            Serial.print(trame_brute.data[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
    }
}