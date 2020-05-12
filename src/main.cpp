#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

const int SD_ChipSelectPin = 10;
const int speakerPin = 9;
const int receiverPin = 3;
const int LED = 7;

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
  if ( digitalRead(receiverPin) == HIGH) {
    audio.play("APHrob.wav");
    digitalWrite(LED, HIGH);
    delay(10000);
    digitalWrite(LED, LOW);
  } 
}
