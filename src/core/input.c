#include <gb/gb.h>
#include <gbdk/emu_debug.h>

UBYTE previousInputState = 0;

int getXDirectionInput(int x) {
    UBYTE input = joypad();
    if (input & J_LEFT) {
        x = -1;
        return x;
    }
    if (input & J_RIGHT) {
        x = 1;
        return x;
    }
    x = 0;
    return x;
}

int getYDirectionInput(int y) {
    UBYTE input = joypad();
    if (input & J_UP) {
        y = -1;
        return y;
    }
    if (input & J_DOWN) {
        y = 1;
        return y;
    }
    y = 0;
    return y;
}

int getAInput(void) {
    UBYTE input = joypad();
    if (input & J_A && !(previousInputState & J_A)) {
        previousInputState = input;
        return 1;
    }
    previousInputState = input;
    return 0;
}

int getBInput(void) {
    UBYTE input = joypad();
    if (input & J_B && !(previousInputState & J_B)) {
        previousInputState = input;
        return 1;
    }
    previousInputState = input;
    return 0;
}

int getSELECTInput(void) {
    UBYTE input = joypad();
    if (input & J_SELECT) {
        return 1;
    }
    return 0;
}

int getSTARTInput(void) {
    UBYTE input = joypad();
    if (input & J_START) {
        return 1;
    }
    return 0;
}
