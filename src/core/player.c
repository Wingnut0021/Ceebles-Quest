#include <gb/gb.h>
#include <gbdk/emu_debug.h>
#include <gbdk/metasprites.h>
#include <stdint.h>
#include "input.h"
#include "spritemetasprite.h"
#include "sprite_kingboy.h"
#include "worldcollision.h"
#include "util_perfdelay.h"
#include "sound_effects.h"
#include "player.h"


const uint8_t attackCooldown = 20;
int8_t inputX = 0;
int8_t inputY = 0;
uint8_t isAttacking = 0;
uint8_t attackFrameCounter = 0;
uint8_t spriteX = 80; 
uint8_t spriteY = 75;
uint8_t spriteSize = 8;
uint8_t prevSpriteX;
uint8_t prevSpriteY;

union PlayerStats playerStats;
struct SpriteMetaSprite player;


void initializePlayer(void) {
	// Initialize players spawn stats.
	playerStats.maxHealth = 100;
	playerStats.currentHealth = playerStats.maxHealth;

	// Initialize player sprite.
	set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_01 * 16]);
	set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_02 * 16]);
	SPRITES_8x16;
	player.width = 16;
	player.height = 16;
	set_sprite_tile(0, TILE_SLICE_01);
	player.spriteids[0] = 0;
	set_sprite_tile(1, TILE_SLICE_02);
	player.spriteids[1] = 1;

	// Spawn player at location.
	player.x = spriteX;
	player.y = spriteY;
	SHOW_SPRITES;
}


void moveMetaSprite(struct SpriteMetaSprite* player) {
	move_sprite(player->spriteids[0], spriteX - 4, spriteY - 6); // Offsets the X and Y so 8 size tile is in middle of 16 sprite.
	move_sprite(player->spriteids[1], spriteX + spriteSize - 4, spriteY - 6); 
}

void updatePlayerAnimation(uint8_t direction, uint8_t isMoving, uint8_t isAttacking) {
	static uint8_t oldDirection;
	static uint8_t frameCounter = 0;
	if (!oldDirection == direction) {
		frameCounter = 0;
	} 
	if (isMoving == 0) {
		frameCounter = 0;
		direction = oldDirection;
		switch (direction) {
			case 0:
				// Cycle through frames 15 and 16
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_01 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_02 * 16]);
				break;
			case 2:
				// Cycle through frames 13 and 14
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_19 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_20 * 16]);
				break;
			case 4:
				// Cycle through frames 17 and 18
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_07 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_08 * 16]);
				break;
			case 6:
				// Cycle through frames 13 and 14
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_13 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_14 * 16]);
				frameCounter = 0;
				break;
		}
	}
	if (direction == 0) {
		switch (frameCounter) {
			case 5:
				// Cycle through frames 03 and 04
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_03 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_04 * 16]);
				break;
			case 10:
				// Cycle through frames 01 and 02
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_01 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_02 * 16]);
				break;
			case 15:
				// Cycle through frames 05 and 06
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_05 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_06 * 16]);
				break;
			case 20:
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_01 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_02 * 16]);
				frameCounter = 0;
				break;
		}
	}
	if (direction == 2) {
		switch (frameCounter) {
			case 5:
				// Cycle through frames 21 and 22
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_21 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_22 * 16]);
				break;
			case 10:
				// Cycle through frames 19 and 20
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_19 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_20 * 16]);
				break;
			case 15:
				// Cycle through frames 23 and 24
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_23 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_24 * 16]);
				break;
			case 20:
				// Cycle through frames 19 and 20
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_19 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_20 * 16]);
				frameCounter = 0;
				break;
		}
	}
	if (direction == 4) {
		switch (frameCounter) {
			case 5:
				// Cycle through frames 09 and 10
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_09 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_10 * 16]);
				break;
			case 10:
				// Cycle through frames 07 and 08 IDLE
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_07 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_08 * 16]);
				break;
			case 15:
				// Cycle through frames 11 and 12
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_11 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_12 * 16]);
				break;
			case 20:
				// Cycle through frames 07 and 08
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_07 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_08 * 16]);
				frameCounter = 0;
				break;
		}
	}
	if (direction == 6) {
		switch (frameCounter) {
			case 5:
				// Cycle through frames 15 and 16
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_15 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_16 * 16]);
				break;
			case 10:
				// Cycle through frames 13 and 14
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_13 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_14 * 16]);
				break;
			case 15:
				// Cycle through frames 17 and 18
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_17 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_18 * 16]);
				break;
			case 20:
				// Cycle through frames 13 and 14
				set_sprite_native_data(0, 2, &sprite_kingboy[TILE_SLICE_13 * 16]);
				set_sprite_native_data(2, 2, &sprite_kingboy[TILE_SLICE_14 * 16]);
				frameCounter = 0;
				break;
		}
	}
	oldDirection = direction;
	frameCounter++;
}

void attackPlayer(void) {
	isAttacking = getAInput(isAttacking) + attackFrameCounter;
	if (isAttacking == 1) {
		EMU_printf("attacking");
		if (attackFrameCounter == 0) {
			attackSound();
			attackFrameCounter = attackCooldown;
		}
	}
	if (attackFrameCounter != 0) {
		attackFrameCounter--;
	}
	EMU_printf("%d", attackFrameCounter);
}

void movePlayer(void) {
	inputX = getXDirectionInput(inputX);
	inputY = getYDirectionInput(inputY);
	uint8_t nextX = spriteX + inputX;
	uint8_t nextY = spriteY + inputY;
	uint8_t nextTileIsSolidX = isTileSolid(nextX / 8, spriteY / 8);
	uint8_t nextTileIsSolidY = isTileSolid(spriteX / 8, nextY / 8);
	
	if (nextTileIsSolidX == 0) {
		prevSpriteX = spriteX;
		spriteX = nextX;
	}
	if (nextTileIsSolidY == 0) {
		prevSpriteY = spriteY;
		spriteY = nextY;
	}
	if (inputY < 0) {
		if (inputX < 0) {
			updatePlayerAnimation(2, 1, 0); //3
		} else if (inputX > 0) {
			updatePlayerAnimation(6, 1, 0); //5
		} else {
			updatePlayerAnimation(4, 1, 0);
		}
	} else if (inputY > 0) {
		if (inputX < 0) {
			updatePlayerAnimation(2, 1, 0); //1
		} else if (inputX > 0) {
			updatePlayerAnimation(6, 1, 0); //7
		} else {
			updatePlayerAnimation(0, 1, 0);
		}
	} else {
		if (inputX < 0) {
			updatePlayerAnimation(2, 1, 0);
		} else if (inputX > 0) {
			updatePlayerAnimation(6, 1, 0);
		} else {
			updatePlayerAnimation(1, 0, 0);
		}
	}
	moveMetaSprite(&player);
}

void updatePlayer(void) {
	attackPlayer();
	if (isAttacking == 0) {
		movePlayer();
	}
}
