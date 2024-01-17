#include <gb/gb.h>
#include <stdio.h>
#include <string.h>
#include "ts_splash.h"
#include "scenemanager.h"

static UINT16 splashTimer;

void initializeSplashScene(void) {
    // Set time splashscreen to say on screen.
    splashTimer = 300;
    // Set background tileset and tilemap
    set_bkg_data(0, ts_splash_size, ts_splash);
    set_bkg_tiles(0, 0, tm_splash_width, tm_splash_height, tm_splash);
    DISPLAY_ON;
    SHOW_BKG;
    fadeIn(10);
}

void endSplashScene(void) {
    fadeOut(10);
}
// Switch scene when timer ends
void updateSplashScene(void) {
    if (splashTimer > 0) {
        splashTimer--;
    } else {
        endSplashScene();
        HIDE_BKG;
        delay(10);
        DISPLAY_OFF;
        switchScene(MAIN_MENU);
    }
}