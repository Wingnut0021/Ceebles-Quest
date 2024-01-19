#include <gb/gb.h>
#include <stdio.h>

#include "bg_samplemap_tileset.h"
#include "bg_samplemap_tilemap.h"
#include "scenemanager.h"
#include "player.h"

void initializeSampleLevelScene(void) {
    // Set background tileset and tilemap
    set_bkg_data(0, bg_samplemap_tileset_size, bg_samplemap_tileset);
    set_bkg_tiles(0, 0, bg_samplemap_tilemap_width, bg_samplemap_tilemap_height, bg_samplemap_tilemap);
    fadeIn(100);
    SHOW_BKG;
    delay(100);
    initializePlayer();
    DISPLAY_ON;
}

void updateSampleLevelScene(void) {
    updatePlayer();
}