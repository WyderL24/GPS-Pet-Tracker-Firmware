#include "audio.h"
#include <driver/adc.h>

void initAudio() {
  analogReadResolution(10);
}

MicData readMicrophone() {
  int micValue = analogRead(MIC_PIN);
  return {micValue};
}

void playSoundIfRequested() {
  tone(SPEAKER_PIN, 1000, 200); // simple beep
}