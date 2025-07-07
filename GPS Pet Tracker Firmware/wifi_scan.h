#ifndef WIFI_SCAN_H
#define WIFI_SCAN_H

struct WiFiData {
  int networksFound;
};

void initWiFiScan();
WiFiData scanWiFi();

#endif