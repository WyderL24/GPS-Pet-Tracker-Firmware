#ifndef GPS_MODULE_H
#define GPS_MODULE_H

struct GPSData {
  float latitude;
  float longitude;
  bool valid;
};

void initGPS();
GPSData getGPSLocation();

#endif