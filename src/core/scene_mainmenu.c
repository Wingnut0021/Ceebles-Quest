#include <gb/gb.h>
#include <stdio.h>
#include "ts_mainmenu.h"
#include "scenemanager.h"
#include "sound_effects.h"

void pressStart(void) {
    startSound();
    fadeOut(10);
    HIDE_BKG;
    DISPLAY_OFF;
    switchScene(SAMPLE_LEVEL);
}

void initializeMainMenuScene(void) {
    set_bkg_data(0, ts_mainmenu_size, ts_mainmenu);
    set_bkg_tiles(0, 0, tm_mainmenu_width, tm_mainmenu_height, tm_mainmenu);
    SHOW_BKG;
    fadeIn(10);
    DISPLAY_ON;
    waitpad(J_START);
    pressStart();
}

void updateMainMenuScene(void) {
    //animate sprite here or allow menu selection.
}