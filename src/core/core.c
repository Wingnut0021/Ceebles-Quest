#include <gb/gb.h>
#include "scenemanager.h"
#include "scenes.h"

void core_run(void) {
    initializeScene(SPLASH);
    while (1) {
        wait_vbl_done();
        updateScene();
    }
}