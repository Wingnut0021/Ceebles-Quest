#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scenes.h"

/**
 * Fades in the scene with the specified fade speed.
 *
 * @param fadeSpeed The speed at which the scene should fade in.
 */
void fadeIn(int fadeSpeed);
/**
 * Fades out the current scene with the specified fade speed.
 *
 * @param fadeSpeed The speed at which the scene fades out.
 */
void fadeOut(int fadeSpeed);
/**
 * Clears the tilemap.
 */
void clearTilemap(void);

/**
 * Initializes the scene with the specified initial scene.
 *
 * @param initialScene The initial scene to be set.
 */
void initializeScene(enum Scene initialScene);

/**
 * Updates the current scene.
 */
void updateScene(void);

/**
 * Switches the current scene to the specified new scene.
 *
 * @param newScene The new scene to be switched to.
 */
void switchScene(enum Scene newScene);

#endif