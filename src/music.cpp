#include "music.h"
#include <Arduino.h>

int melody_alert_on[] = {392, 392, 392, 311, 466, 392, 311, 466, 392, 587, 587, 587, 622, 466, 370, 311, 466, 392, 
    784, 392, 392, 784, 740, 698, 659, 622, 659, 0, 415, 554, 523, 494, 466, 440, 466, 0, 311, 370, 311, 370, 466, 392, 
    466, 587, 784, 392, 392, 784, 740, 698, 659, 622, 659, 0, 415, 554, 523, 494, 466, 440, 466, 0, 311, 370, 311, 466, 392, 311, 466, 392};

int delay_alert_on[] = {600, 600, 600, 450, 150, 600, 450, 150, 1200, 600, 600, 600, 450, 150, 600, 450, 150, 1200, 
    600, 450, 150, 600, 450, 150, 150, 150, 300, 300, 300, 600, 450, 150, 150, 150, 300, 300, 300, 600, 450, 150, 600, 
    450, 150, 1200, 600, 450, 150, 600, 450, 150, 150, 150, 300, 300, 300, 600, 450, 150, 150, 150, 300, 300, 300, 600, 
    450, 150, 600, 450, 150, 1200};

int melody_alert_off[] = {523, 392, 523, 587, 523, 784, 698, 784, 1047, 932, 880, 784, 880, 698, 784, 392, 523, 698, 
    523, 784, 523, 698, 880, 523, 698, 784, 784, 784, 784, 523, 523, 523, 784, 698, 784, 880, 698, 784, 784, 784, 932, 
    784, 784, 784, 932, 932, 1047, 175, 175, 175, 175, 233, 233, 233, 233, 262, 311, 311, 311, 415, 415, 415, 622, 622, 
    622, 698, 698, 698, 698, 932, 1245, 1245, 1245, 1397};

int delay_alert_off[] = {36, 63, 94, 89, 83, 1224, 52, 63, 417, 99, 83, 83, 89, 83, 1339, 89, 73, 83, 73, 339, 73, 83, 
    104, 68, 120, 438, 52, 73, 130, 385, 130, 99, 688, 89, 104, 141, 73, 859, 104, 89, 927, 224, 99, 68, 94, 63, 1474, 
    391, 78, 57, 78, 380, 68, 52, 63, 448, 52, 57, 68, 94, 63, 78, 73, 36, 78, 406, 73, 52, 78, 417, 63, 52, 78, 500};

Music::Music(int pinBuzzer) {
    this->pinBuzzer = uint8_t(pinBuzzer);
}

void Music::Play(int melody[], int delays[], int length, float delay_multi) {
    for (int thisNote = 0; thisNote < length; thisNote++) {
        int noteDuration = (delays[thisNote] * delay_multi);
        if (melody[thisNote] != 0)
            tone(this->pinBuzzer, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(this->pinBuzzer);
    }
}

void Music::PlayAlertOn() {
    this->Play(melody_alert_on, delay_alert_on, MELODY_LENGTH_ALERT_ON, 0.8);
}

void Music::PlayAlertOff() {
    this->Play(melody_alert_off, delay_alert_off, MELODY_LENGTH_ALERT_OFF, 1.5);
}
