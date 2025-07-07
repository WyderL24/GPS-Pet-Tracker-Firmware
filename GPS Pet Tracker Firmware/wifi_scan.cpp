#include "wifi_scan.h"
#include <WiFi.h>

void initWiFiScan() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

WiFiData scanWiFi() {
  int n = WiFi.scanNetworks(false, true);
  return {n};
}