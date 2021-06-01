#include "Floor.h"
#include "Skyscraper.h"

Floor::Floor(int floorId)
{
    // parse Floors arrays
    std::string const *floorInstr = floors[floorId];
    this->theme = themes[floorId];

    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        Tile *test = new Tile(QString(floorInstr[i].data()), theme);
        this->tiles[i] = test;
    }

    // set tiles position
    // calculate tile cordinates (2D) based on 1D index
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        int x = i % FLOOR_WIDTH;
        int y = (i - x) / FLOOR_WIDTH;

        // get and place tile
        Tile *tile = this->tiles[i];
        tile->setPos(x * 64, y * 64);
    }

    // init enemies
    for (int i = 0; i < MAX_ENEMIES; i++)
        this->enemies[i] = NULL;
    for (int i = 0; i < this->enemyNbr(); i++)
    {
        Enemy *enemy = new Enemy(KAREN);
        this->enemies[i] = enemy;
        // search where to put the enemy
        Tile *where = NULL;
        for (int j = 0; where == NULL; j++)
        {
            Tile *current = this->tiles[j];
            if (current->spawnType() == ENEMY && this->enemy(current->posX(), current->posY()) == NULL)
                where = current;
        }
        enemy->posX(where->posX());
        enemy->posY(where->posY());
    }
}

void Floor::removeEnemy(Enemy *enemy)
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (this->enemies[i] == enemy)
            this->enemies[i] = NULL;
    }
}

Tile *Floor::tile(int x, int y)
{
    Tile *test = this->tiles[x + y * FLOOR_WIDTH];
    return test;
}

Enemy* Floor::enemy(int x, int y)
{
    // for each element in array enemies
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        // if there is an actual enemy defined here
        if (this->enemies[i])
        {
            // if the enemy position is the same as asked
            if(this->enemies[i]->posX() == x && this->enemies[i]->posY() == y)
            {
                // return that enemy
                return this->enemies[i];
            }
        }
    }

    // if no enemy is in the requested tile, return NULL
    return NULL;
}

int Floor::enemyNbr()
{
    int sum = 0;
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        if (tiles[i]->spawnType() == ENEMY)
        {
            sum++;
        }
    }
    return sum;
}

Tile *Floor::startingPos()
{
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        if (this->tiles[i]->spawnType() == PLAYER)
            return this->tiles[i];
    }

    return NULL;
}

Tile *Floor::fromUpPos()
{
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        if (this->tiles[i]->spawnType() == PLAYER_FROMUP)
            return this->tiles[i];
    }

    return NULL;
}

Tile *Floor::fromDownPos()
{
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        if (this->tiles[i]->spawnType() == PLAYER_FROMDOWN)
            return this->tiles[i];
    }

    return NULL;
}
