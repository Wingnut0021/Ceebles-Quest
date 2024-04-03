#include <gb/gb.h>

uint8_t duration = 0;

void soundCore(void) {
    NR52_REG = 0x80; // Turns on sound
    NR50_REG = 0x77; // Sets volume to max
    NR51_REG = 0xFF; // Select all channels
}

void startSound(void) {
    soundCore();
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;

    delay(1000);
}

void openMenuSound(void) {
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
}

void closeMenuSound(void) {
    NR10_REG = 0x06;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
}

void attackSound(void) {
    NR10_REG = 0x26;
    NR11_REG = 0x15;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
    duration = 3;
}