#include <gb/gb.h>
#include <stdio.h>

#include "ts_sampleMap.h"
#include "scenemanager.h"
#include "player.h"

void initializeSampleLevelScene(void) {
    // Set background tileset and tilemap
    set_bkg_data(0, ts_sampleMap_size, ts_sampleMap);
    set_bkg_tiles(0, 0, tm_sampleMap_width, tm_sampleMap_height, tm_sampleMap);
    fadeIn(100);
    SHOW_BKG;
    delay(100);
    initializePlayer();
    DISPLAY_ON;
}

void updateSampleLevelScene(void) {
    
}