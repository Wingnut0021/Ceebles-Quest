#include <gb/gb.h>
#include <stdio.h>
#include "tiles/NumberTiles.h"
#include "input/Buttons.c"


void intro(void) 
{
    printf("Welcome to the game!\n");
    waitpad(J_START);
}
void main(void)
{
    intro();
    // Load tileset into GB memory
    set_bkg_data(0, 1, NumberTiles);

    // Fill entire screen with 1st tile


    // Show background
    SHOW_BKG;
    DISPLAY_ON;

    while (1)
    {
        input();
        wait_vbl_done();
    }

}