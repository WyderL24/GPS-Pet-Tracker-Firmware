#include "config.h"
#include "gps_module.h"
#include "sensors.h"
#include "ble_module.h"
#include "wifi_scan.h"
#include "led.h"
#include "ota.h"
#include "power.h"
#include "audio.h"

void setup() {
  Serial.begin(115200);
  initLED();
  initGPS();
  initSensors();
  initBLE();
  initWiFiScan();
  initAudio();
  initOTA();
  showStatusLED("booting");
}

void loop() {
  if (OTARequested()) {
    handleOTA();
  }

  if (isMotionDetected()) {
    GPSData gps = getGPSLocation();
    WiFiData wifi = scanWiFi();
    TempData temp = readTemperature();
    MicData mic = readMicrophone();
    
    advertiseBLE(gps, wifi, temp, mic);
    playSoundIfRequested();
  }

  enterDeepSleep(MIN_SLEEP_MINUTES);
}