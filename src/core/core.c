#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>
#include <string.h>
#include <rand.h>

#include "input.h"
#include "scenemanager.h"
#include "scenes.h"
#include "player.h"
#include "win_hud.h"


void core_run(void) {
    initializeScene(SPLASH);
    while (1) {
        updateScene();
        updateHud(); 
        wait_vbl_done();
    }
}