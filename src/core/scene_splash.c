#include <gb/gb.h>
#include <stdio.h>
#include "ts_house.h"
#include "scenemanager.h"
#include <string.h>

static UINT16 splashTimer;

void initializeSplashScene(void) {
    splashTimer = 300;
    DISPLAY_ON;
    SHOW_BKG;
    set_bkg_data(0, ts_house_size, ts_house);
    set_bkg_tiles(0, 0, tm_house_width, tm_house_height, tm_house);
}
void updateSplashScene(void) {
    // Update the splash scene
    if (splashTimer > 0) {
        // Decrement the timer
        splashTimer--;
    } else {
        // Switch to the main menu scene after 2 seconds
        switchScene(MAIN_MENU);
    }
}