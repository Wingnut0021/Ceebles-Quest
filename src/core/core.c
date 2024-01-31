#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>
#include <string.h>
#include <rand.h>
#include <gbdk/emu_debug.h>

#include "input.h"
#include "scenemanager.h"
#include "scenes.h"
#include "player.h"
#include "win_hud.h"



void VBlankHandler(void) {
    
}



void initializeCore(void) {
    add_VBL(VBlankHandler);
    enable_interrupts();
    initializeScene(SPLASH);
}

void pauseGameplay(void) {

}

void core_run(void) {
    while (1) {
        updateScene();
        updateHud();
        wait_vbl_done();
    }
}