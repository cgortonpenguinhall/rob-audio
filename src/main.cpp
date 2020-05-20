// This file conrols Rob's voice
// Use https://ttsmp3.com/ to record a message and download as mp3
// then use https://audio.online-convert.com/convert-to-wav to convert to wav
// using 8-bit, 16000 Hz, mono, PCM unsigned 8-bit settings

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

const int SD_ChipSelectPin = 10;
const int speakerPin = 9;
const int receiverPin = 3;
const int LED = 7;
int audioFile = 0;

char file0[] = "APHrob.wav";
char file1[] = "rob2.wav";
char file2[] = "rob3.wav";
char* files[] = {file0, file1,file2};

TMRpcm audio;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  pinMode(receiverPin, INPUT);
  pinMode(LED, OUTPUT);

  audio.speakerPin = speakerPin;
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  audio.speakerPin = speakerPin;
  audio.setVolume(5);
}

void loop() {
  if (digitalRead(receiverPin) == HIGH) {
    audio.play(files[audioFile % 3]);
    audioFile++;
    digitalWrite(LED, HIGH);
    delay(10000);
    digitalWrite(LED, LOW);
  }
}