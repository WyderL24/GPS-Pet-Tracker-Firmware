#include "sensors.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;

void initSensors() {
  mpu.begin();
}

bool isMotionDetected() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  return fabs(a.acceleration.x) > 0.5 || fabs(a.acceleration.y) > 0.5;
}

TempData readTemperature() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  return {temp.temperature};
}