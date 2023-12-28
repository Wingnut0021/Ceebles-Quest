#include <gb/gb.h>
#include <stdio.h>
#include "bg_ground.h"

void initializeSampleLevelScene(void) {
    // Set background tileset and tilemap
    set_bkg_data(0, bg_ground_size, bg_ground);
    set_bkg_tiles(0, 0, bg_ground_sampleTilemap_width, bg_ground_sampleTilemap_height, bg_ground_sampleTilemap);
    SHOW_BKG;
    delay(100);
    DISPLAY_ON;
}

void updateSampleLevelScene(void) 
{
    wait_vbl_done();
}