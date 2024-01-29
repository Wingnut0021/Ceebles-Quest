#include <gb/gb.h>


int getXDirectionInput(int x) {
    UBYTE input = joypad();
    if (input & J_LEFT) {
        x = -1;
        return x;
    } else if (input & J_RIGHT) {
        x = 1;
        return x;
    }
    return x;
}

int getYDirectionInput(int y) {
    UBYTE input = joypad();
    if (input & J_UP) {
        y = -1;
        return y;
    } else if (input & J_DOWN) {
        y = 1;
        return y;
    }
    return y;
}

int getAInput(int a) {
    UBYTE input = joypad();
    if (input & J_A) {
        a = -1;
        return a;
    } else if (input & J_A) {
        a = 1;
        return a;
    }
    return a;
}

int getBInput(int b) {
    UBYTE input = joypad();
    if (input & J_B) {
        b = -1;
        return b;
    } else if (input & J_B) {
        b = 1;
        return b;
    }
    return b;
}

int getSELECTInput(int select) {
    UBYTE input = joypad();
    if (input & J_SELECT) {
        select = -1;
        return select;
    } else if (input & J_SELECT) {
        select = 1;
        return select;
    }
    return select;
}

int getSTARTInput(int start) {
    UBYTE input = joypad();
    if (input & J_START) {
        start = -1;
        return start;
    } else if (input & J_START) {
        start = 1;
        return start;
    }
    return start;
}