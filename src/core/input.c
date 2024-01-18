#include <gb/gb.h>



void getInput_BUTTON_A(void) {

}

void getInput_BUTTON_B(void) {

}

void getInput_BUTTON_START(void) {

}

void getInput_BUTTON_SELECT(void) {

}

void getInput_BUTTON_UP(void) {

}

void getInput_BUTTON_DOWN(void) {

}

void getInput_BUTTON_LEFT(void) {

}

void getInput_BUTTON_RIGHT(void) {

}

void getInput_BUTTON_UP_RIGHT(void) {

}

void getInput_BUTTON_UP_LEFT(void) {

}

void getInput_BUTTON_DOWN_RIGHT(void) {

}

void getInput_BUTTON_DOWN_LEFT(void) {

}

void getInput(void) {
    UBYTE input = joypad();

    if (input & J_A) {
        getInput_BUTTON_A();
    }
    if (input & J_B) {
        getInput_BUTTON_B();
    }
    if (input & J_START) {
        getInput_BUTTON_START();
    }
    if (input & J_SELECT) {
        getInput_BUTTON_SELECT();
    }
    if (input & J_UP) {
        getInput_BUTTON_UP();
    }
    if (input & J_DOWN) {
        getInput_BUTTON_DOWN();
    }
    if (input & J_RIGHT) {
        getInput_BUTTON_RIGHT();
    }
    if (input & J_LEFT) {
        getInput_BUTTON_LEFT();
    }
    if ((input & J_UP) && (input & J_RIGHT)) {
        getInput_BUTTON_UP_RIGHT();
    }
    if ((input & J_UP) && (input & J_LEFT)) {
        getInput_BUTTON_UP_LEFT();
    }
    if ((input & J_DOWN) && (input & J_RIGHT)) {
        getInput_BUTTON_DOWN_RIGHT();
    }
    if ((input & J_DOWN) && (input & J_LEFT)) {
        getInput_BUTTON_DOWN_LEFT();
    }
}