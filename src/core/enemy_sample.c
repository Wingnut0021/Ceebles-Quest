#include <gb/gb.h>
#include <gbdk/emu_debug.h>

#include "sprite_test.h"

uint8_t enemySpriteX = 2; 
uint8_t enemySpriteY = 144;


void initializeEnemy(void) {
    set_sprite_native_data(4, 2, sprite_test);
    set_sprite_tile(4, 4);
    move_sprite(4, enemySpriteX, enemySpriteY);
}

void updateEnemy(void) {
    scroll_sprite(4, 1, 0);
}