#include <gb/gb.h>
#include <stdio.h>
#include "core.h"

int main(void) {
    initializeCore();
    core_run();
    return 0;
}
