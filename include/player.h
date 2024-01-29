#ifndef PLAYER_H
#define PLAYER_H


void updatePlayerAnimation(uint8_t direction);
void initializePlayer(void);
void moveMetasprite(struct SpriteMetaSprite* player);
void movePlayer(void);
void updatePlayer(void);

#endif