#include "ble_module.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLEAdvertising* pAdvertising;

void initBLE() {
  BLEDevice::init("PetTracker");
  BLEServer* pServer = BLEDevice::createServer();
  pAdvertising = BLEDevice::getAdvertising();
}

void advertiseBLE(GPSData gps, WiFiData wifi, TempData temp, MicData mic) {
  std::string data = "Lat:" + String(gps.latitude).c_str() + 
                     " Lon:" + String(gps.longitude).c_str();
  BLEAdvertisementData advData;
  advData.setName("PetTracker");
  advData.setManufacturerData(data);
  pAdvertising->setAdvertisementData(advData);
  pAdvertising->start();
}