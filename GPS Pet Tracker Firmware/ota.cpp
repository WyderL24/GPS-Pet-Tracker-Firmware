#include "ota.h"
#include <ArduinoOTA.h>

void initOTA() {
  ArduinoOTA.begin();
}

bool OTARequested() {
  return millis() % OTA_CHECK_INTERVAL < 1000;
}

void handleOTA() {
  ArduinoOTA.handle();
}