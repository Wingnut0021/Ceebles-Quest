#include <gb/gb.h>
#include <stdio.h>
#include "ts_mainmenu.h"



void initializeMainMenuScene(void) {
    DISPLAY_ON;
    SHOW_BKG;
    set_bkg_data(0, ts_mainmenu_size, ts_mainmenu);
    set_bkg_tiles(0, 0, tm_mainmenu_width, tm_mainmenu_height, tm_mainmenu);
    
    // Wait for the start button to be pressed.
    waitpad(J_START);  
    HIDE_BKG;
}

void updateMainMenuScene(void) {
}