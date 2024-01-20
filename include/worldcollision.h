#ifndef WORLDCOLLISION_H
#define WORLDCOLLISION_H

#include <gb/gb.h>

extern const unsigned char bg_samplemap_collision[];

uint8_t isTileSolid(uint8_t tileX, uint8_t tileY);

#endif