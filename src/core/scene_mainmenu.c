#include <gb/gb.h>
#include <stdio.h>
#include "ts_splash.h"



void initializeMainMenuScene(void) 
{
    DISPLAY_ON;
    wait_vbl_done();
    delay(100);
    SHOW_BKG;
    set_bkg_data(0, ts_splash_size, ts_splash);
    set_bkg_tiles(0, 0, tm_splash_width, tm_splash_height, tm_splash);
    
    // Wait for the start button to be pressed.
    waitpad(J_START);  
    HIDE_BKG;
}

void updateMainMenuScene(void) 
{

}