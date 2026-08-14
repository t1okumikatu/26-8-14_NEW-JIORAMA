#include "constant.h"

// 正転
void forward(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(in1, pwm);
  ledcWrite(in2, 0);
}

// 逆転
void reverse(uint32_t pwm) {
  if (pwm > VALUE_MAX) {
    pwm = VALUE_MAX;
  }
  ledcWrite(in1, 0);
  ledcWrite(in2, pwm);
}

// ブレーキ
void brake() {
  ledcWrite(in1, VALUE_MAX);
  ledcWrite(in2, VALUE_MAX);
}

// 空転
void coast() {
  ledcWrite(in1, 0);
  ledcWrite(in2, 0);
}