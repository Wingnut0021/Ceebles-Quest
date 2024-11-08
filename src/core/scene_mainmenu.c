#include <gb/gb.h>
#include <stdio.h>
#include "font_characters.h"
#include "scenemanager.h"
#include "sound_effects.h"
#include "sprite_test.h"
#include "ts_mainmenu.h"
#include "util.h"

#define SPRITE_START_X 56
#define SPRITE_START_Y 112
#define MAX_STRING_SIZE 17

#define SPRITE_COL_1 72
#define SPRITE_COL_2 80
#define SPRITE_COL_3 88
#define SPRITE_COL_4 96
#define SPRITE_COL_5 104

#define SPRITE_ROW_1 116
#define SPRITE_ROW_2 108

uint8_t mainmenuSelection = 0;


void pressStart(void) {
    startSound();
    clear_sprite_data(0);
    perf_delay(1);
    HIDE_SPRITES;
    fadeOut(10);
    HIDE_BKG;
    DISPLAY_OFF;
    switchScene(SAMPLE_LEVEL);
}

void initializeMainMenuScene(void) {
    const uint8_t sprite_tiles[] = { TILE_SLICE_01, 46, 47, 28, 45, 47, 45, 46, 27, 44, 46 };
	const uint8_t sprite_positions[][2] = {
		{ SPRITE_START_X, SPRITE_START_Y },
		{ SPRITE_COL_1, SPRITE_ROW_1 }, { SPRITE_COL_2, SPRITE_ROW_1 },
		{ SPRITE_COL_3, SPRITE_ROW_1 }, { SPRITE_COL_4, SPRITE_ROW_1 },
		{ SPRITE_COL_5, SPRITE_ROW_1 }, { SPRITE_COL_1, SPRITE_ROW_2 },
		{ SPRITE_COL_2, SPRITE_ROW_2 }, { SPRITE_COL_3, SPRITE_ROW_2 },
		{ SPRITE_COL_4, SPRITE_ROW_2 }, { SPRITE_COL_5, SPRITE_ROW_2 }
	};

    clear_sprite_data(0);
    set_bkg_data(0, ts_mainmenu_size, ts_mainmenu);
    set_bkg_tiles(0, 0, tm_mainmenu_width, tm_mainmenu_height, tm_mainmenu);
    set_sprite_native_data(0, 1, &sprite_test[TILE_SLICE_01]);
    set_sprite_native_data(1, 64, &char_sprites[6][7]);

    for (uint8_t i = 0; i < 11; ++i) {
        set_sprite_tile(i, sprite_tiles[i]);
        move_sprite(i, sprite_positions[i][0], sprite_positions[i][1]);
    }

    SHOW_SPRITES;
    SPRITES_8x8;
    SHOW_BKG;
    fadeIn(10);
    DISPLAY_ON;
}

void updateMainMenuScene(void) {  
    if (joypad() & J_START ) {
        if (mainmenuSelection == 0) {
            pressStart();
        } else if (mainmenuSelection == 1) {
            pressStart();
        }
    }
    if (joypad() & J_DOWN) {
        move_sprite(0, SPRITE_START_X, SPRITE_START_Y + 16);
        mainmenuSelection = 1;
    }
    if (joypad() & J_UP) {
        move_sprite(0, SPRITE_START_X, SPRITE_START_Y);
        mainmenuSelection = 0;
    }
}