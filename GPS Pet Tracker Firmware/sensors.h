#ifndef SENSORS_H
#define SENSORS_H

struct TempData {
  float temperature;
};

void initSensors();
bool isMotionDetected();
TempData readTemperature();

#endif