#include <gb/gb.h>
#include <stdio.h>

#include "bg_samplemap_tileset.h"
#include "bg_samplemap_tilemap.h"
#include "scenemanager.h"
#include "player.h"
#include "win_hud.h"

void initializeSampleLevelScene(void) {
    set_bkg_data(0, bg_samplemap_tileset_size, bg_samplemap_tileset);
    set_bkg_tiles(0, 0, bg_samplemap_tilemap_width, bg_samplemap_tilemap_height, bg_samplemap_tilemap);
    fadeIn(100);
    initializeHud();
    initializePlayer();
    SHOW_BKG;
	DISPLAY_ON;
}

void updateSampleLevelScene(void) {
    updatePlayer();
    if (joypad() & J_A ) {
        fadeOut(10);
    }
    if (joypad() & J_B ) {
        fadeIn(10);
    }
}