#include <gb/gb.h>
#include <stdio.h>

void perf_delay(UINT8 numloops) {
    UINT8 i;
    for(i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}