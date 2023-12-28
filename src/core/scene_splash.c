#include <gb/gb.h>
#include <stdio.h>
#include "ts_splash.h"
#include "scenemanager.h"
#include <string.h>

static UINT16 splashTimer;

void initializeSplashScene(void) {
    // Set time splashscreen to say on screen.
    splashTimer = 300;
    // Set background tileset and tilemap
    set_bkg_data(0, ts_splash_size, ts_splash);
    set_bkg_tiles(0, 0, tm_splash_width, tm_splash_height, tm_splash);
    DISPLAY_ON;
    delay(100);
    SHOW_BKG;
}

// Switch scene when timer ends
void updateSplashScene(void) {
    if (splashTimer > 0) {
        splashTimer--;
    } else {
        HIDE_BKG;
        delay(100);
        DISPLAY_OFF;
        switchScene(MAIN_MENU);
    }
}