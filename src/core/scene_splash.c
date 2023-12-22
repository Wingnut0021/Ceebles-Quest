#include <gb/gb.h>
#include <stdio.h>
#include "ts_splash.h"
#include "scenemanager.h"
#include <string.h>

static UINT16 splashTimer;

void initializeSplashScene(void) {
    splashTimer = 300;
    DISPLAY_ON;
    SHOW_BKG;
    set_bkg_data(0, ts_splash_size, ts_splash);
    set_bkg_tiles(0, 0, tm_splash_width, tm_splash_height, tm_splash);
}

void updateSplashScene(void) {
    if (splashTimer > 0) {
        splashTimer--;
    } else {
        HIDE_BKG;
        switchScene(MAIN_MENU);
    }
}