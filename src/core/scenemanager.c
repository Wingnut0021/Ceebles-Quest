#include "scenemanager.h"
#include "scene_mainmenu.h" 
#include "scene_splash.h"
#include "scenes.h"

static enum Scene currentScene;

void initializeScene(enum Scene initialScene) {
    currentScene = initialScene;
    switchScene(initialScene);
}

void updateScene(void) {
    switch (currentScene) {
        case SPLASH:
            updateSplashScene();
            break;
        case MAIN_MENU:
            updateMainMenuScene();
            break;
    }
}

void switchScene(enum Scene newScene) {
    currentScene = newScene;

    switch (newScene) {
        case SPLASH:
            initializeSplashScene();
            break;
        case MAIN_MENU:
            initializeMainMenuScene();
            break;
    }
}