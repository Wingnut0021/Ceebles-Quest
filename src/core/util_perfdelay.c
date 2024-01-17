#include <gb/gb.h>
#include <stdio.h>

void perf_delay(UINT8 numloops) {
    UINT8 ii;
    for(ii = 0; ii < numloops; ii++) {
        wait_vbl_done();
    }
}