#include <gb/gb.h>
#include <stdio.h>
#include "tiles/NumberTiles.h"
#include "input/Buttons.c"
#include "scene/intro.c"
#include "scene/mainmenu.c"



void main(void)
{
    intro();
    mainmenu();
    // Load tileset into GB memory
    set_bkg_data(0, 1, NumberTiles);

    // Fill entire screen with 1st tile


    // Show background
    SHOW_BKG;
    DISPLAY_ON;

    while (1)
    {
        inputDirection();
        wait_vbl_done();
    }

}