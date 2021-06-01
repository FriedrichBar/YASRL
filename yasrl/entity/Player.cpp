#include "Player.h"
#include "../Game.h"
#include "../map/Floor.h"

#include <QPixmap>
#include <QDebug>

extern Game *game;

Player::Player(PlayerType type) : Character()
{
    this->floorNbr = 0;

    // set base stats
    switch (type)
    {
    case MR_NOBODY:
        this->timeLeftBeforeDying = mrNobody.timeLeftBeforeDying;
        this->baseHealth = mrNobody.baseHealth;
        this->baseStrength = mrNobody.baseStrength;
        this->baseAgility = mrNobody.baseAgility;
        this->setPixmap(QPixmap(":/img/players/mrnobody.png"));
    }

    this->currentHealth = this->baseHealth;
    this->backpack = NULL;
}

void Player::move()
{
    if (this->status_ != IDLE)
    {
        int distance = SPEED / TPS;
        switch (this->status_)
        {
        case GOING_NORTH:
            this->setPos(x(), y() - distance);
            break;
        case GOING_SOUTH:
            this->setPos(x(), y() + distance);
            break;
        case GOING_WEST:
            this->setPos(x() - distance, y());
            break;
        case GOING_EAST:
            this->setPos(x() + distance, y());
            break;
        }

        if((int)x() % TILE_SIZE == 0 && (int)y() % TILE_SIZE == 0)
        {
            this->status_ = IDLE;
        }
    }
}

void Player::status(PlayerStatus status)
{
    // we don't want going back to IDLE if the player is currently moving
    if (status != IDLE)
    {
        bool flag = true;

        // calculate to which coords the player would go
        int newX = this->posX();
        int newY = this->posY();

        switch (status)
        {
        case GOING_NORTH:
            newY--;
            break;
        case GOING_SOUTH:
            newY++;
            break;
        case GOING_WEST:
            newX--;
            break;
        case GOING_EAST:
            newX++;
            break;
        }

        // we don't want the player to go out of the grid
        if (newX < 0 || newY < 0 || newX > FLOOR_WIDTH - 1 || newY > FLOOR_HEIGHT - 1)
            flag = false;

        // the player can only walk on floors without enemies
        Floor *floor = game->exploration()->currentFloor();
        Tile *tile = floor->tile(newX, newY);
        if (tile->tileType() != FLOOR) // check if FLOOR
        {
            flag = false;
        }
        else if (floor->enemy(newX, newY)) // then check if there is an enemy
        {
            flag = false;
        }

        if (flag)
            this->status_ = status;
    }
}

PlayerStatus Player::status()
{
    return this->status_;
}
