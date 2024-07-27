#include <gb/gb.h>

void perf_delay(const uint8_t numloops) {
    for(uint8_t i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}

void clear_sprite_data(const uint8_t sprite_index) {
    for(uint8_t i = 0; i < 40; i++) {
        set_sprite_tile(sprite_index + i, 0); // Set sprite tile to 0 (empty)
        move_sprite(sprite_index + i, 0, 0); // Move any active sprites off screen (prevent unused from appearing)
    }
}