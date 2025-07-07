#ifndef AUDIO_H
#define AUDIO_H

struct MicData {
  int level;
};

void initAudio();
MicData readMicrophone();
void playSoundIfRequested();

#endif