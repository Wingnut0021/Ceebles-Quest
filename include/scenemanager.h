#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scenes.h"

void clearTilemap(void);
void initializeScene(enum Scene initialScene);
void updateScene(void);
void switchScene(enum Scene newScene);

#endif