#include <gb/gb.h>
#include <gbdk/emu_debug.h>

#include "input.h"
#include "sprite_test.h"
#include "worldcollision.h"

uint8_t spriteX = 80; 
uint8_t spriteY = 75;
uint8_t prevSpriteX;
uint8_t prevSpriteY;
int8_t playerVelocityX = 0;
int8_t playerVelocityY = 0;
int8_t playerAcceleration = 1;
int8_t playerDeceleration = 1;
int8_t maxVelocity = 1;


void initializePlayer(void) {
    SPRITES_8x16;
    set_sprite_native_data(0, 2, sprite_test);
    set_sprite_tile(0, 0);
    move_sprite(0, spriteX, spriteY);
    EMU_printf("%d", spriteX);
    EMU_printf("%d", spriteY);
    SHOW_SPRITES;
}

void movePlayer(void) {
    int8_t inputX = getXDirectionInput(inputX);
    int8_t inputY = getYDirectionInput(inputY);
    playerVelocityX += playerAcceleration * inputX;
    playerVelocityY += playerAcceleration * inputY;
    if (playerVelocityX > maxVelocity) {
        playerVelocityX = maxVelocity;
    } else if (playerVelocityX < -maxVelocity) {
        playerVelocityX = -maxVelocity;
    }
    if (playerVelocityY > maxVelocity) {
        playerVelocityY = maxVelocity;
    } else if (playerVelocityY < -maxVelocity) {
        playerVelocityY = -maxVelocity;
    }
    if (inputX == 0) {
        if (playerVelocityX > 0) {
            playerVelocityX -= playerDeceleration;
            if (playerVelocityX < 0) {
                playerVelocityX = 0;
            }
        } else if (playerVelocityX < 0) {
            playerVelocityX += playerDeceleration;
            if (playerVelocityX > 0) {
                playerVelocityX = 0;
            }
        }
    }
    if (inputY == 0) {
        if (playerVelocityY > 0) {
            playerVelocityY -= playerDeceleration;
            if (playerVelocityY < 0) {
                playerVelocityY = 0;
            }
        } else if (playerVelocityY < 0) {
            playerVelocityY += playerDeceleration;
            if (playerVelocityY > 0) {
                playerVelocityY = 0;
            }
        }
    }
    uint8_t nextX = spriteX + playerVelocityX;
    uint8_t nextY = spriteY + playerVelocityY;
    uint8_t nextTileIsSolidX = isTileSolid(nextX / 8, spriteY / 8);
    uint8_t nextTileIsSolidY = isTileSolid(spriteX / 8, nextY / 8);
    if (nextTileIsSolidX == 0) {
        prevSpriteX = spriteX;
        spriteX = nextX;
    } else {
        playerVelocityX = 0; 
    }
    if (nextTileIsSolidY == 0) {
        prevSpriteY = spriteY;
        spriteY = nextY;
    } else {
        playerVelocityY = 0;
    }
    move_sprite(0, spriteX, spriteY);
}

void updatePlayer(void) {
    movePlayer();
}
