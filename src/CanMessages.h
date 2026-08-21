#pragma once
#include "CanManager.h"

enum motor_id_t: uint8_t {
  RIGHT,
  LEFT,
};

CAN_STRUCT(MOTEUR, 200,
  motor_id_t motor_id;
  bool  etat;
  uint8_t speed;
);