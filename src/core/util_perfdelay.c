#include <gb/gb.h>
#include <stdio.h>

void perf_delay(uint8_t numloops) {
    uint8_t i;
    for(i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}

void clear_sprite_data(uint8_t sprite_index) {
    uint8_t i;
    for(i = 0; i < 40; i++) {
        set_sprite_tile(sprite_index + i, 0); // Set sprite tile to 0 (empty)
        move_sprite(sprite_index + i, 0, 0); // Move any active sprites off screen (prevent unused from appearing)
    }
}