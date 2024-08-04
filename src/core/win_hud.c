#include <gb/gb.h>

#include "input.h"
#include "core.h"
#include "bg_hud_tilemap.h"
#include "sound_effects.h"
#include "util.h"
#include "sprite_inventory_items.h"
#include "spritemetasprite.h"

#define HUD_DOWN_POS 128
#define HUD_UP_POS 0
#define HUD_MOVE_SPD 2
#define INV_COL_1 20
#define INV_COL_2 28
#define INV_COL_3 80
#define INV_COL_4 88
#define INV_ROW_1 48
#define INV_ROW_2 80
#define INV_ROW_3 112

uint8_t hudMoving = 0;
uint8_t hudCurrentPosition;


struct SpriteMetaSprite item;


void initializeHud(void) {
    set_win_tiles(0, 0, 20, 18, bg_hud_tilemap);
    move_win(0, HUD_DOWN_POS);
    scroll_win(7,0);
    hudCurrentPosition = HUD_DOWN_POS;
	gamePaused = 0;
    SHOW_WIN;
}

void displayInventoryItems(void) {
	const uint8_t tile_slices[] = {
		MYSTERY_TILE_SLICE_01, MYSTERY_TILE_SLICE_02, POTION_TILE_SLICE_01, POTION_TILE_SLICE_02,
		MYSTERY_TILE_SLICE_01, MYSTERY_TILE_SLICE_02, MYSTERY_TILE_SLICE_01, MYSTERY_TILE_SLICE_02,
		MYSTERY_TILE_SLICE_01, MYSTERY_TILE_SLICE_02, MYSTERY_TILE_SLICE_01, MYSTERY_TILE_SLICE_02
	};

	for (uint8_t i = 0; i < sizeof(tile_slices) / sizeof(tile_slices[0]); i++) {
		set_sprite_native_data(4 + i * 2, 2, &sprite_inventory_items[tile_slices[i] * 16]);
		set_sprite_tile(4 + i, 4 + i * 2);
	}

	const uint8_t positions[][2] = {
		{INV_COL_1, INV_ROW_1}, {INV_COL_2, INV_ROW_1}, {INV_COL_1, INV_ROW_2}, {INV_COL_2, INV_ROW_2},
		{INV_COL_1, INV_ROW_3}, {INV_COL_2, INV_ROW_3}, {INV_COL_3, INV_ROW_1}, {INV_COL_4, INV_ROW_1},
		{INV_COL_3, INV_ROW_2}, {INV_COL_4, INV_ROW_2}, {INV_COL_3, INV_ROW_3}, {INV_COL_4, INV_ROW_3}
	};

	for (uint8_t i = 0; i < sizeof(positions) / sizeof(positions[0]); i++) {
		move_sprite(4 + i, positions[i][0], positions[i][1]);
	}

	SHOW_SPRITES;
}

void moveHud(const uint8_t targetPosition, const int8_t scrollStep) {
	hudMoving = 1;
	HIDE_SPRITES;
	while (hudCurrentPosition != targetPosition) {
		perf_delay(1);
		scroll_win(0, scrollStep);
		hudCurrentPosition += scrollStep;
	}
	hudMoving = 0;
	SHOW_SPRITES;
}

void hideInventoryItems(void) {
	for (uint8_t i = 0; i < 12; i++) {
		hide_sprite(4 + i);
	}
}

void hidePlayer(void) {
	hide_sprite(0);
	hide_sprite(1);
	hide_sprite(2);
	hide_sprite(3);
}

void updateHud(void) {
	uint8_t inputStart = 0;
	inputStart = getSTARTInput(inputStart);
	if (inputStart == 1 && hudCurrentPosition == HUD_DOWN_POS && hudMoving == 0) {
		displayInventoryItems();
		hidePlayer();
		openMenuSound();
		HIDE_SPRITES;
		moveHud(HUD_UP_POS, -HUD_MOVE_SPD);
	} else if (inputStart == 1 && hudCurrentPosition == HUD_UP_POS && hudMoving == 0) {
		closeMenuSound();
		hidePlayer();
		hideInventoryItems();
		moveHud(HUD_DOWN_POS, HUD_MOVE_SPD);
	}
	if (hudCurrentPosition < HUD_DOWN_POS) {
		hidePlayer();
		gamePaused = 0;
	}
	if (hudCurrentPosition == HUD_DOWN_POS) {
		gamePaused = 1;
	}
}
