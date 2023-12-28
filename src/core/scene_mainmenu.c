#include <gb/gb.h>
#include <stdio.h>
#include "ts_mainmenu.h"
#include "scenemanager.h"

void initializeMainMenuScene(void) {
    // Set background tileset and tilemap
    set_bkg_data(0, ts_mainmenu_size, ts_mainmenu);
    set_bkg_tiles(0, 0, tm_mainmenu_width, tm_mainmenu_height, tm_mainmenu);
    SHOW_BKG;
    delay(100);
    DISPLAY_ON;
    // Wait for the start button to be pressed.
    waitpad(J_START); 
    HIDE_BKG;
    DISPLAY_OFF;
    switchScene(SAMPLE_LEVEL); 
}

void updateMainMenuScene(void) {
}