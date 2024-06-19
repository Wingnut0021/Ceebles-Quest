#include <gb/gb.h>
#include <stdio.h>

#include "bg_samplemap_tileset.h"
#include "bg_samplemap_tilemap.h"
#include "bg_samplemap_collision.h"
#include "scenemanager.h"
#include "player.h"
#include "win_hud.h"
#include "enemy_sample.h"

void initializeSampleLevelScene(void) {
    set_bkg_data(0, bg_samplemap_tileset_size, bg_samplemap_tileset);
    set_bkg_tiles(0, 0, bg_samplemap_tilemap_width, bg_samplemap_tilemap_height, bg_samplemap_tilemap);
    fadeIn(100);
    initializeHud();
    initializeEnemy(64, 64);
    initializePlayer();
    DISPLAY_ON;
    SHOW_BKG;
}

void updateSampleLevelScene(void) {
    updatePlayer();
    updateEnemy();
    if (joypad() & J_A ) {
        fadeOut(10);
    }
    if (joypad() & J_B ) {
        fadeIn(10);
    }
}