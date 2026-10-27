#include "CanManager.h"

CAN_STRUCT(SensorData, 100,
  float temperature;
  float humidity;
);

#ifdef ARDUINO_ARCH_ESP32
#define CAN_TX_PIN GPIO_NUM_12
#define CAN_RX_PIN GPIO_NUM_11
#endif

CanManager can;
unsigned long lastSendTime = 0;

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
    if (millis() - lastSendTime > 2000) {
        lastSendTime = millis();

        SensorData mySensor;
        mySensor.temperature = 24.5;
        mySensor.humidity = 60.0;
        
        can.send(mySensor);
        Serial.println("Message envoyé : ID=100");
    }
}