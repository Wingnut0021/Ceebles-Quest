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
    if (splashTimer > 0) {
        splashTimer--;
    } else {
        switchScene(MAIN_MENU);
    }
}