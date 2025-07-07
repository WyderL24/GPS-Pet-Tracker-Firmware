#include "led.h"
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

void initLED() {
  pixels.begin();
  pixels.setBrightness(20);
}

void showStatusLED(const char* status) {
  if (strcmp(status, "booting") == 0) pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  else if (strcmp(status, "tracking") == 0) pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
}