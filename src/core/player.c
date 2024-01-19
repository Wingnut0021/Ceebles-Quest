#include <gb/gb.h>
#include <gbdk/emu_debug.h>

#include "input.h"
#include "sprite_test.h"
#include "bg_samplemap_collision.h"

#define minBoundsX = 16;
#define maxBoundsX = 144;

UINT8 spriteX = 80; // Pass these values in when called, for door entries etc.
UINT8 spriteY = 75;

void initializePlayer(void) {
    SPRITES_8x8;
    set_sprite_data(0, 1, sprite_test);
    set_sprite_tile(0, 0);
    move_sprite(0, spriteX, spriteY);
    EMU_printf("%d", spriteX);
    EMU_printf("%d", spriteY);
    SHOW_SPRITES;
}
void normalizeSpeed(void) {
    //normalizeSpeed for diagonal inputs.
}

void movePlayer(void) {
    int inputX = getXDirectionInput(inputX);
    int inputY = getYDirectionInput(inputY);
    scroll_sprite(0, inputX, inputY);
        if (spriteX > 15 && spriteX < 153) {
        spriteX += inputX;
        if (spriteX == 15) {
            spriteX = 16;
            move_sprite(0, spriteX, spriteY);
            }
        if (spriteX == 153) {
            spriteX = 152; 
            move_sprite(0, spriteX, spriteY);
            }
    if (spriteY > 32 && spriteY < 129) {
        spriteY += inputY;
        if (spriteY == 32) {
            spriteY = 33;
            move_sprite(0, spriteX, spriteY);
            }
        if (spriteY == 129) {
            spriteY = 128; 
            move_sprite(0, spriteX, spriteY);
            }
        }
    }
}

void updatePlayer(void) {
    movePlayer();
    EMU_printf("%d", spriteY);

}
