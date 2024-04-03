#include <gb/gb.h>
#include <gbdk/console.h>
#include <gbdk/emu_debug.h>
#include "bg_samplemap_collision.h"


extern const unsigned char bg_samplemap_collision[];

uint8_t isTileSolid(uint8_t tileX, uint8_t tileY) {
    if (tileX < bg_samplemap_collision_width && tileY < bg_samplemap_collision_height) {
        uint16_t tileIndex = tileY * bg_samplemap_collision_width + tileX;
        if (bg_samplemap_collision[tileIndex] == 0xFF) {
            return 1; // Solid
        } else if (bg_samplemap_collision[tileIndex] == 0x00) {
            return 0; // Not solid
        } 
    }
    return 1;
}