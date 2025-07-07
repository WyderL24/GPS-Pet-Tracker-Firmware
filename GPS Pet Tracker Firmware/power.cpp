#include "power.h"
#include <esp_sleep.h>

void enterDeepSleep(int minutes) {
  esp_sleep_enable_timer_wakeup((uint64_t)minutes * 60 * 1000000);
  esp_deep_sleep_start();
}