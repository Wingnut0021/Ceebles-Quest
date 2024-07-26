#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include <gbdk/metasprites.h>
#include <stdio.h>

#include "input.h"
#include "core.h"
#include "bg_hud_tileset.h"
#include "bg_hud_tilemap.h"
#include "sound_effects.h"
#include "util_perfdelay.h"
#include "sprite_inventory_items.h"
#include "spritemetasprite.h"


#define HUD_DOWN_POSITION 128
#define HUD_UP_POSITION 0


uint8_t hudMoving = 0;
uint8_t hudCurrentPosition;
extern uint8_t gamePaused;

struct SpriteMetaSprite item;


void initializeHud(void) {
    set_win_tiles(0, 0, 20, 18, bg_hud_tilemap);
    move_win(0, HUD_DOWN_POSITION);
    scroll_win(7,0); // This seems hacky,
    hudCurrentPosition = HUD_DOWN_POSITION;
    SHOW_WIN;
}

void displayInventoryItems(void) {
    set_sprite_1bpp_data(6, 2, &sprite_inventory_items[POTION_TILE_SLICE_01 * 16]);
    set_sprite_1bpp_data(8, 2, &sprite_inventory_items[POTION_TILE_SLICE_02 * 16]);
    SPRITES_8x16;
    set_sprite_tile(6, 6);
    set_sprite_tile(8, 7);
    move_sprite(6, 20, 100);
    move_sprite(8, 28, 100);
    SHOW_SPRITES;
}

void updateHud(void) {
    auto uint8_t inputStart = getSTARTInput(inputStart);
    if (inputStart == 1 && hudCurrentPosition == 128 && hudMoving == 0) {
        displayInventoryItems();
        hudMoving = 1;
        openMenuSound();
        HIDE_SPRITES;
        while (hudCurrentPosition != 0) {
            perf_delay(1);
            scroll_win(0,-2);
            hudCurrentPosition -= 2;
        }
        if (hudCurrentPosition == 0) {
            SHOW_SPRITES;
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