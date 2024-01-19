#include <gb/gb.h>
#include <stdio.h>

#include "bg_hud_tileset.h"
#include "bg_hud_tilemap.h"

#define hudDownPosition 128
#define hudUpPosition 0


void moveHudUP(void) {
    move_win(0, hudUpPosition);
}
void moveHudDOWN(void) {
    move_win(0, hudDownPosition);
}

void initializeHud(void) {
    set_win_tiles(0, 0, 5, 1, bg_hud_tilemap);
    moveHudDOWN();
    SHOW_WIN;
}


void updateHud(void) {

}