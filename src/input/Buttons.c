#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>

void input(void)
{
    while(1) 
        {
        switch(joypad()) 
            {
            case J_RIGHT : // If joypad() is equal to RIGHT
                printf("Right\n");
                delay(100);
                break;
            case J_LEFT : // If joypad() is equal to LEFT
                printf("Left\n");
                delay(100);
                break;
            case J_UP : // If joypad() is equal to UP
                printf("Up\n");
                delay(100);
                break;
            case J_DOWN : // If joypad() is equal to DOWN
                printf("Down\n");
                delay(100);
                break;
            case J_START : // If joypad() is equal to START
                printf("Start\n");
                delay(100);
                break;
            case J_SELECT : // If joypad() is equal to SELECT
                printf("Select\n");
                delay(100);
                break;
            case J_A : // If joypad() is equal to A
                printf("A\n");
                delay(100);
                break;
            case J_B : // If joypad() is equal to B
                printf("B\n");
                delay(100);
                break;			
            default :
                break;
            }
        }
}
