#ifndef BLE_MODULE_H
#define BLE_MODULE_H

#include "gps_module.h"
#include "sensors.h"

struct MicData {
  int level;
};

void initBLE();
void advertiseBLE(GPSData gps, WiFiData wifi, TempData temp, MicData mic);

#endif