#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include "sprite_test.h"

uint8_t enemySpriteX = 2;
uint8_t enemySpriteY = 144;


void initializeEnemy(uint8_t enemySpriteX, uint8_t enemySpriteY) {
    set_sprite_data(4, 2, sprite_test);
    set_sprite_tile(4, 4);
    move_sprite(4, enemySpriteX, enemySpriteY);
    SHOW_SPRITES;
}

void updateEnemy(void) {
    scroll_sprite(4, 1, 0);
}