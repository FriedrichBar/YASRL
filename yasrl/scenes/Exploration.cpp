#include "Exploration.h"
#include "../Game.h"
#include "../map/Floor.h"
#include "../map/ChestLootTable.h"

#include <QRandomGenerator>
#include <chrono>

#include <QDebug>

extern Game *game;

Exploration::Exploration(QGraphicsView *parent) : QGraphicsSceneSized(parent)
{
    int maxFloorsNbr = sizeof(this->renderedFloors) / sizeof(*this->renderedFloors);

    for (int i = 0; i < maxFloorsNbr; i++)
    {
        this->renderedFloors[i] = 0;
    }
}

// level rendering

void Exploration::renderFloor(int lvl)
{
    // if level hasnt already been parsed
    if (!this->renderedFloors[lvl])
    {
        this->renderedFloors[lvl] = new Floor(lvl);

        // if it's level 0 set player starting position
        if (lvl == 0)
        {
            Tile *startingTile = this->renderedFloors[lvl]->startingPos();
            game->player->posX(startingTile->posX());
            game->player->posY(startingTile->posY());
        }
    }
    this->currentFloor_ = this->renderedFloors[lvl];

    // clear scene
    QList items = this->items();
    for (auto i = items.begin(); i != items.end(); i++)
    {
        QGraphicsItem *item = *i;
        this->removeItem(item);
    }

    // render parsed arrays
    for (int i = 0; i < FLOOR_HEIGHT * FLOOR_WIDTH; i++)
    {
        Tile *tile = this->currentFloor()->tiles[i];
        this->addItem(tile);
    }

    //render enemies
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (this->currentFloor()->enemies[i])
            this->addItem(this->currentFloor()->enemies[i]);
    }

    this->addItem(game->player); // has to be placed last to be on top
}

// event management

void Exploration::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        if (game->player->status() == IDLE)
            game->player->status(GOING_NORTH);
        break;
    case Qt::Key_Down:
        if (game->player->status() == IDLE)
            game->player->status(GOING_SOUTH);
        break;
    case Qt::Key_Left:
        if (game->player->status() == IDLE)
            game->player->status(GOING_WEST);
        break;
    case Qt::Key_Right:
        if (game->player->status() == IDLE)
            game->player->status(GOING_EAST);
        break;
    case Qt::Key_Space:
        if (game->player->status() == IDLE) // we don't want some nasty position conflict
            this->actionKeyHandler();
        break;
    case Qt::Key_Tab:
        if (game->player->status() == IDLE)
            game->displayInventory();
        break;
    default:
        qDebug() << "Exploration::keyPressEvent unknown key :" << event->key();
    }
}

void Exploration::actionKeyHandler()
{
    // get surrounding tiles
    int pX = game->player->posX();
    int pY = game->player->posY();
    bool north = true, south = north, west = north, east = north;

    if (pX == 0) west = false;
    if (pX == FLOOR_WIDTH - 1) east = false;
    if (pY == 0) north = false;
    if (pY == FLOOR_HEIGHT - 1) south = false;

    Tile* tiles[north + south + east + west];
    int index = 0;
    if (north)
    {
        tiles[index] = this->currentFloor()->tile(pX, pY - 1);
        index++;
    }
    if (south)
    {
        tiles[index] = this->currentFloor()->tile(pX, pY + 1);
        index++;
    }
    if (west)
    {
        tiles[index] = this->currentFloor()->tile(pX - 1, pY);
        index++;
    }
    if (east)
    {
        tiles[index] = this->currentFloor()->tile(pX + 1, pY);
        index++; // now index is the size of the tiles array
    }

    // search for chest, enemy or stairs
    Tile *chest = NULL, *enemy = chest, *stairs = chest;
    for (int i = 0; i < index; i++)
    {
        if (tiles[i]->tileType() == CHEST)
            chest = tiles[i];
        else if (tiles[i]->tileType() == STAIRS_ASC || tiles[i]->tileType() == STAIRS_DSC)
            stairs = tiles[i];
        else if (this->currentFloor()->enemy(tiles[i]->posX(), tiles[i]->posY()))
            enemy = tiles[i];
    }

    // manage chest
    if (chest)
    {
        // get loot table
        int id;
        switch (game->exploration()->currentFloor()->theme)
        {
        case DRUGSTORE:
            id = 0;
            break;
        case SUPERMARKET:
            id = 1;
            break;
        case CLOTHING_STORE:
            id = 2;
            break;
        case PUB:
            id = 3;
            break;
        case GYM:
            id = 4;
            break;
        }

        // iterate through loot table
        int seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        QRandomGenerator *gen = new QRandomGenerator(seed);
        gen->bounded(1);
        for (int i = 0; i < lootSize[id]; i++)
        {
            // generate rnd nbr between 0 and 1
            double rnd = gen->generateDouble();

            if (rnd < lootChances[id][i])
            {
                // instanciate the item
                IStorable *item = IStorable::getItemInstance(lootItems[id][i]);

                // add it to the inventory
                if (! game->player->inventory()->add(item))
                    qDebug() << "Exploration::actionKeyHandler item couldn't be added to inventory";
            }
        }
    }

    // manage enemy
    else if (enemy)
    {
        // true win, false lose
        Enemy *opponent = this->currentFloor()->enemy(enemy->posX(), enemy->posY());
        if (Fight::fightSim(opponent))
        {
            enemy->spawnType(NONE);
            this->currentFloor()->removeEnemy(opponent);
            this->removeItem(opponent);
        }
        else
        {
            game->displayFight();
        }
    }

    // manage stairs
    else if (stairs)
    {
        int currentFloor = game->player->floorNbr;
        TileType stairsType = stairs->tileType();
        int newFloor = stairsType == STAIRS_ASC ? currentFloor + 1 : currentFloor - 1;

        game->player->floorNbr = newFloor;
        game->displayExploration();

        // move player to the right position
        Tile *newPos = stairsType == STAIRS_ASC ? this->currentFloor()->fromDownPos() : this->currentFloor()->fromUpPos();
        game->player->posX(newPos->posX());
        game->player->posY(newPos->posY());
    }
}

// getters

Floor *Exploration::currentFloor()
{
    return this->currentFloor_;
}
