#include "gps_module.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial ss(1);

void initGPS() {
  ss.begin(9600, SERIAL_8N1, 16, 17); // RX, TX
}

GPSData getGPSLocation() {
  GPSData data = {0.0, 0.0, false};
  while (ss.available()) {
    gps.encode(ss.read());
    if (gps.location.isUpdated()) {
      data.latitude = gps.location.lat();
      data.longitude = gps.location.lng();
      data.valid = true;
      break;
    }
  }
  return data;
}