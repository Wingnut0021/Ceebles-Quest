#include "scenemanager.h"
#include "scene_mainmenu.h" 
#include "scene_splash.h"
#include "scene_samplelevel.h"
#include "scenes.h"

static enum Scene currentScene;

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
