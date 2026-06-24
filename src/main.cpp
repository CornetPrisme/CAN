#include "CanManager.h"

CanManager can;

CAN_STRUCT(BOUTTON, 106, 
  bool  boutton1;
);



void setup() {
    Serial.begin(115200);
    #ifdef ARDUINO_ARCH_ESP32
      can.init(GPIO_NUM_11, GPIO_NUM_12);
    #endif
    #ifdef ARDUINO_ARCH_STM32
      can.init();
    #endif
    

}
void loop() {
    can.update();
}