#include <gb/gb.h>
#include <gbdk/console.h>
#include "scenemanager.h"
#include "scenes.h"
#include "win_hud.h"

extern uint8_t hudCurrentPosition;
extern uint8_t gamePaused;

void VBlankHandler(void) {
    
}

void initializeCore(void) {
    add_VBL(VBlankHandler);
    enable_interrupts();
    initializeScene(SPLASH);
}

void pauseGameplay(void) {
    gamePaused = 1;
}

void core_run(void) {
	while (1) {
        updateScene();
        updateHud();
        wait_vbl_done();
    }
}