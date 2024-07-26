#include "scenemanager.h"
#include "scene_mainmenu.h" 
#include "scene_splash.h"
#include "scene_samplelevel.h"
#include "scenes.h"
#include "util_perfdelay.h"

static enum Scene currentScene;

void fadeIn(int fadeSpeed) {
    uint8_t fadeValues[] = {0xFF, 0xFE, 0xF9, 0xE4};
    for(uint8_t i = 0; i < sizeof(fadeValues); i++) {
        BGP_REG = fadeValues[i];
        perf_delay(fadeSpeed);
    }
}

void fadeOut(int fadeSpeed) {
    uint8_t fadeValues[] = {0xE4, 0xF9, 0xFE, 0xFF};
    for(uint8_t i = 0; i < sizeof(fadeValues); i++) {
        BGP_REG = fadeValues[i];
        perf_delay(fadeSpeed);
    }
}

void clearTilemap(void) {
    uint8_t emptyTile = 0;
    for (uint8_t y = 0; y < 18; y++) {
        for (uint8_t x = 0; x < 20; x++) {
            set_bkg_tiles(x, y, 1, 1, &emptyTile);
        }
    }
}

void updateScene(void) {
    switch (currentScene) {
        case SPLASH:
            updateSplashScene();
            break;
        case MAIN_MENU:
            updateMainMenuScene();
            break;
        case SAMPLE_LEVEL:
            updateSampleLevelScene();
            break;
    }
}

void switchScene(enum Scene newScene) {
    currentScene = newScene;
    clearTilemap();
    switch (newScene) {
        case SPLASH:
            initializeSplashScene();
            break;
        case MAIN_MENU:
            initializeMainMenuScene();
            break;
        case SAMPLE_LEVEL:
            initializeSampleLevelScene();
            break;
    }
    SHOW_BKG;
}

void initializeScene(enum Scene initialScene) {
    switchScene(initialScene);
}
