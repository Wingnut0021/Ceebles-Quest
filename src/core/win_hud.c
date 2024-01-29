#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include <stdio.h>

#include "input.h"
#include "bg_hud_tileset.h"
#include "bg_hud_tilemap.h"

#define hudDownPosition 128
#define hudUpPosition 0

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
    if (inputStart == 255 && !hudCurrentPosition == 0) {
        scroll_win(0, -2);
        hudCurrentPosition -= 2;
        HIDE_SPRITES;
    }
    else if (inputStart == 255 && hudCurrentPosition == 0) {
        scroll_win(0, 0);
        hudCurrentPosition -= 0;
    }
    else if (hudCurrentPosition == 128) {
        SHOW_SPRITES;
    }
    else {
        scroll_win(0, 2);
        hudCurrentPosition += 2;
    }
}