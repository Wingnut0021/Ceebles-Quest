#ifndef PLAYER_H
#define PLAYER_H

union PlayerStats;
struct SpriteMetaSprite;

typedef union PlayerStats {
    uint8_t currentHealth;
    uint8_t maxHealth;
    uint8_t attackPower;
} PlayerStats;

void updatePlayerAnimation(uint8_t direction, uint8_t isMoving, uint8_t isAttacking);
void initializePlayer(void);
void moveMetaSprite(struct SpriteMetaSprite* player);
void movePlayer(void);
void updatePlayer(void);

#endif