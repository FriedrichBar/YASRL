#ifndef FLOOR_H
#define FLOOR_H

#include "../entity/Enemy.h"
#include "Tile.h"

#include <string>

const int FLOOR_WIDTH = 20;
const int FLOOR_HEIGHT = 12;
const int TILE_SIZE = 64;
const int MAX_ENEMIES = 8;

class Floor
{
public:
    Floor(int floorId);
    void removeEnemy(Enemy *enemy);

    // getters
    Tile* tile(int x, int y);
    Enemy* enemy(int x, int y);
    int enemyNbr();
    Tile* startingPos();
    Tile* fromUpPos();
    Tile* fromDownPos();
    FloorTheme theme;
    Enemy *enemies[8];
    Tile *tiles[FLOOR_WIDTH * FLOOR_HEIGHT];
};

#endif // FLOOR_H
