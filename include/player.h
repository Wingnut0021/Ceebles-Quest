#ifndef PLAYER_H
#define PLAYER_H
#include <gb/gb.h>

struct PlayerStats;
struct SpriteMetaSprite;

typedef struct PlayerStats {
    uint8_t currentHealth;
    uint8_t maxHealth;
    uint8_t attackPower;
} PlayerStats;

void updatePlayerAnimation(uint8_t direction, uint8_t isMoving);
void initializePlayer(void);
void moveMetaSprite(struct SpriteMetaSprite* player);
void movePlayer(void);
void updatePlayer(void);

#endif // PLAYER_H