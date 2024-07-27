#include "data/enemy.h"
#include "data/enemy_types.h"

void initEnemy(FEnemy *enemy, const EEnemyType type, const uint8_t x, const uint8_t y, const uint8_t health,
			   void (*move)(FEnemy *), void (*attack)(FEnemy *)) {
	enemy->type = type;
	enemy->x = x;
	enemy->y = y;
	enemy->health = health;
	enemy->move = move;
	enemy->attack = attack;
	}