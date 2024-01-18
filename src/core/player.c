#include <gb/gb.h>

#include "input.h"
#include "sprite_test.h"


void initializePlayer(void) {
    SPRITES_8x8;
    set_sprite_data(0, 1, sprite_test);
    set_sprite_tile(0, 0);
    move_sprite(0, 80, 75);
    SHOW_SPRITES;
}

void normalizeSpeed(void) {

}

void updatePlayer(void) {
    getInput();
    scroll_sprite(0,1,1);
}
