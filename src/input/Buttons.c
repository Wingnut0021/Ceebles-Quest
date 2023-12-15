#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>

uint8_t joydata;
uint8_t joydirection;
uint8_t joyreceive;

void inputButton(void)
{
    while(1)
    {
        if (joydata & J_START) // If START is pressed
        {
            printf("START");
            continue;
        }
        if (joydata & J_SELECT) // If SELECT is pressed
        {
            printf("SELECT");
            continue;
        }
        if (joydata & J_A) // If A is pressed
        {
            printf("A");
            continue;
        }
        if (joydata & J_B) // If B is pressed
        {
            printf("B");
            continue;
        }
    }
}
void inputDirection(void)
{
    while(1) 
    {
        printf("%d\n", joydirection);
        joydata = joypad();
        // Directional buttons
        if (joydata & J_RIGHT) // If RIGHT is pressed
        {
            if (joydata & J_DOWN) // if RIGHT and DOWN are pressed
            {
                joydirection = 3;
                joyreceive = 1;
                continue;
            }
            else if (joydata & J_UP) // if RIGHT and UP are pressed
            {
                joydirection = 1;
                joyreceive = 1;
                continue;
            } 
            else 
            {
                joydirection = 2;
                joyreceive = 1;
                continue;
            }
        }
        if (joydata & J_LEFT) // If LEFT is pressed
        {
            if (joydata & J_DOWN) // if LEFT and DOWN are pressed
            {
                joydirection = 5;
                joyreceive = 1;
                continue;
            }
            else if (joydata & J_UP) // if LEFT and UP are pressed
            {
                joydirection = 7;
                joyreceive = 1;
                continue;
            } 
            else 
            {
                joydirection = 6;
                joyreceive = 1;
                continue;
            }
        }
        if (joydata & J_DOWN) // If DOWN is pressed
        {
            joydirection = 4;
            joyreceive = 1;
            continue;
        }
        if (joydata & J_UP) // If UP is pressed
        {
            joydirection = 0;
            joyreceive = 1;
            continue;
        }
    }
}
