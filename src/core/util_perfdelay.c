#include <gb/gb.h>
#include <stdio.h>

/** Move the Window relative to its current position.

    @param x   Number of pixels to move the window on the __X axis__
               \n Range: -128 - 127
    @param y   Number of pixels to move the window on the __Y axis__
               \n Range: -128 - 127

    @see move_win
*/
void perf_delay(uint8_t numloops) {
    uint8_t i;
    for(i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}