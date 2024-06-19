#include "enemy.h"
#include "enemy_types.h"

void initEnemy(Enemy *enemy, EnemyType type, uint8_t x, uint8_t y, uint8_t health,
			   void (*move)(Enemy *), void (*attack)(Enemy *)) {
	enemy->type = type;
	enemy->x = x;
	enemy->y = y;
	enemy->health = health;
	enemy->move = move;
	enemy->attack = attack;
	}