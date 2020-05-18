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
char* files[] = {file0, file1};

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
    audio.play(files[audioFile % 2]);
    audioFile++;
    digitalWrite(LED, HIGH);
    delay(10000);
    digitalWrite(LED, LOW);
  }
}