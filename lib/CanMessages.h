#pragma once
#include "CanManager.h"

enum motor_id_t: uint8_t {
  RIGHT,
  LEFT,
  BOTH,
};

CAN_STRUCT(MOTOR, 200,
  motor_id_t motor_id;
  bool  launch;
  int16_t speed;
);
