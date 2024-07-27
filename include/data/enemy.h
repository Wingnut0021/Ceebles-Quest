#ifndef ENEMY_H
#define ENEMY_H

#include <gb/gb.h>
#include <data/enemy_types.h>

typedef struct FEnemy {
    EEnemyType type;
    uint8_t x, y;
    uint8_t health;
    void (*move)(struct FEnemy *self);
    void (*attack)(struct FEnemy *self);
} FEnemy;

void initEnemy(FEnemy *enemy, EEnemyType type, uint8_t x, uint8_t y, uint8_t health,
               void (*move)(FEnemy *), void (*attack)(FEnemy *));
#endif // ENEMY_H