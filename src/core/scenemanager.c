#include "scenemanager.h"
#include "scene_mainmenu.h" 
#include "scene_splash.h"
#include "scene_samplelevel.h"
#include "scenes.h"
#include "util_perfdelay.h"

static enum Scene currentScene;

void fadeIn(int fadeSpeed) {
    UINT8 i;
    for(i = 0; i < 3; i++) {
        switch(i) {
            case 0:
                BGP_REG = 0xFE;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xE4;
                break;
        }
        perf_delay(fadeSpeed);
    }
}

void fadeOut(int fadeSpeed) {
    UINT8 i;
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0:
                BGP_REG = 0xE4;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xFE;
                break;
            case 3:
                BGP_REG = 0xFF;
                break;
        }
        perf_delay(fadeSpeed);
    }
}

void clearTilemap(void) {
    // Set all tiles to value 0
    UINT8 emptyTile = 0;
    for (UINT8 y = 0; y < 18; y++) {
        for (UINT8 x = 0; x < 20; x++) {
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
    switch (newScene) {
        case SPLASH:
            clearTilemap();
            initializeSplashScene();
            SHOW_BKG;
            break;
        case MAIN_MENU:
            clearTilemap();
            initializeMainMenuScene();
            SHOW_BKG;
            break;
        case SAMPLE_LEVEL:
            clearTilemap();
            initializeSampleLevelScene();
            SHOW_BKG;
            break;
    }
}

void initializeScene(enum Scene initialScene) {
    currentScene = initialScene;
    switchScene(initialScene);
}
