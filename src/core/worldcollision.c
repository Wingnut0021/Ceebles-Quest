#include <gbdk/console.h>
#include "bg_samplemap_collision.h"


extern const unsigned char bg_samplemap_collision[];

uint8_t isTileSolid(const uint8_t tileX, const uint8_t tileY) {
    if (tileX < bg_samplemap_collision_width && tileY < bg_samplemap_collision_height) {
		const uint16_t tileIndex = tileY * bg_samplemap_collision_width + tileX;
        if (bg_samplemap_collision[tileIndex] == 0xFF) {
			return 1; // Solid
		}
		if (bg_samplemap_collision[tileIndex] == 0x00) {
			return 0; // Not solid
		}
	}
    return 1;
}