#ifndef CORE_H
#define CORE_H

#include <gb/gb.h>

uint8_t gamePaused;

void VBlankHandler(void);
void initializeCore(void);
void pauseGameplay(void);
void core_run(void);

#endif