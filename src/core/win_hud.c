#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include <stdio.h>

#include "input.h"
#include "core.h"
#include "bg_hud_tileset.h"
#include "bg_hud_tilemap.h"
#include "sound_effects.h"
#include "util_perfdelay.h"


#define HUD_DOWN_POSITION 128
#define HUD_UP_POSITION 0


uint8_t hudMoving = 0;
uint8_t hudCurrentPosition;
extern uint8_t gamePaused;


void initializeHud(void) {
    set_win_tiles(0, 0, 20, 18, bg_hud_tilemap);
    move_win(0, HUD_DOWN_POSITION);
    scroll_win(7,0); // This seems hacky,
    hudCurrentPosition = HUD_DOWN_POSITION;
    SHOW_WIN;
}

void updateHud(void) {
    uint8_t inputStart = getSTARTInput(inputStart);
    if (inputStart == 1 && hudCurrentPosition == 128 && hudMoving == 0) {
        hudMoving = 1;
        openMenuSound();
        HIDE_SPRITES;
        while (hudCurrentPosition != 0) {
            perf_delay(1);
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
            perf_delay(1);
            scroll_win(0, 2);
            hudCurrentPosition += 2;
        }
        if (hudCurrentPosition == 128) {
            hudMoving = 0;
            SHOW_SPRITES;
            gamePaused = 0;
        }
    }
    if (hudCurrentPosition < 128) {
        gamePaused = 1;
    }
}