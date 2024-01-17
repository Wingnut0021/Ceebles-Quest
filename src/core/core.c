#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>
#include <string.h>
#include <rand.h>


#include "scenemanager.h"
#include "scenes.h"

void core_reset(void) {
    
}

void core_run(void) {
    initializeScene(SPLASH);
    while (1) {
        updateScene();
        wait_vbl_done();
    }
}