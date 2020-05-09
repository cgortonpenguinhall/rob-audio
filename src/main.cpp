#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

const int SD_ChipSelectPin = 53;  // yellow
const int speakerPin = 46;        // brown

TMRpcm audio;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");

  audio.speakerPin = speakerPin;
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  audio.speakerPin = speakerPin;
  audio.setVolume(5);
  audio.play("APHrob.wav");
}

void loop() {
}
