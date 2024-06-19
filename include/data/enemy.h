#ifndef ENEMY_H
#define ENEMY_H

#include <gb/gb.h>
#include <enemy_types.h>

struct Enemy;

typedef struct Enemy {
    EnemyType type;
    uint8_t x, y;
    uint8_t health;
    void (*move)(struct Enemy *self);
    void (*attack)(struct Enemy *self);
} Enemy;

void initEnemy(Enemy *enemy, EnemyType type, uint8_t x, uint8_t y, uint8_t health, 
               void (*move)(struct Enemy *), void (*attack)(struct Enemy *));
#endif