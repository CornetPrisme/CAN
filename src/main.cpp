#include "CanManager.h"

CanManager can;

CAN_STRUCT(BOUTTON, 106, 
  bool  boutton1;
);

CAN_STRUCT(BYE, 110, 
  bool  boutton1;
);

void salut(can_frame_t frame) {
    BOUTTON msg;
    memcpy(&frame.data, &msg, frame.length);
    digitalWrite(10, msg.boutton1);
    Serial.printf("fonction executee mon ami !! \n ");
}

void bye(can_frame_t frame) {
    BYE msg;
    memcpy(&frame.data, &msg, frame.length);
    digitalWrite(10, msg.boutton1);
    Serial.printf("fonction bye bye bye bye executee mon ami !! \n ");
}

void setup() {
    Serial.begin(115200);
    pinMode(10, OUTPUT);
    #ifdef ARDUINO_ARCH_ESP32
      can.init(GPIO_NUM_11, GPIO_NUM_12);
    #endif
    #ifdef ARDUINO_ARCH_STM32
      can.init();
    #endif
    
    can.onReceive(BOUTTON::ID, salut);
    can.onReceive(BYE::ID, bye);
}
void loop() {
    can.update();
}