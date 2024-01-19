#include <gb/gb.h>
#include "input.h"


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