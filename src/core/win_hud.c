#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include <stdio.h>

#include "input.h"
#include "bg_hud_tileset.h"
#include "bg_hud_tilemap.h"
#include "sound_effects.h"


#define hudDownPosition 128
#define hudUpPosition 0


uint8_t hudMoving = 0;
uint8_t hudCurrentPosition;


void initializeHud(void) {
    set_win_tiles(0, 0, 20, 18, bg_hud_tilemap);
    move_win(0, hudDownPosition);
    scroll_win(7,0); // This seems hacky,
    hudCurrentPosition = hudDownPosition;
    SHOW_WIN;
}

void updateHud(void) {
    uint8_t inputStart = getSTARTInput(inputStart);
    if (inputStart == 1 && hudCurrentPosition == 128 && hudMoving == 0) {
        hudMoving = 1;
        openMenuSound();
        HIDE_SPRITES;
        while (hudCurrentPosition != 0) {
            delay(10);
            scroll_win(0,-2);
            hudCurrentPosition -= 2;
        }
        if (hudCurrentPosition == 0) {
            hudMoving = 0;
        }
    }
    else if (inputStart == 1 && hudCurrentPosition == 0 && hudMoving == 0) {
        hudMoving = 1;
        closeMenuSound();
        while (hudCurrentPosition != 128) {
            delay(10);
            scroll_win(0, 2);
            hudCurrentPosition += 2;
        }
        if (hudCurrentPosition == 128) {
            hudMoving = 0;
            SHOW_SPRITES;
        }
    }
}