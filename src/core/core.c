#include <gb/gb.h>
#include <gbdk/console.h>
#include "scenemanager.h"
#include "scenes.h"
#include "win_hud.h"
#include "core.h"

extern uint8_t hudCurrentPosition;
uint8_t gamePaused = 0;

void VBlankHandler(void) {
	// Not sure yet what to use this for.
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