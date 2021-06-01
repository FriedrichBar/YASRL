#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "../item/Backpack.h"

// about the different characters

enum PlayerType
{
    MR_NOBODY
};

static const struct MrNobody
{
    static const int baseHealth = 10;
    static const int baseStrength = 10;
    static const int baseAgility = 10;
    static const int timeLeftBeforeDying = 180;
} mrNobody;

// about the Player class

const int SPEED = 120; // px/sec, should be a multiple of TPS

enum PlayerStatus
{
    IDLE,
    GOING_NORTH,
    GOING_SOUTH,
    GOING_WEST,
    GOING_EAST
};

class Player : public Character
{
public:
    // constructor
    Player(PlayerType type);

    // movement
    void move();
    void status(PlayerStatus status);

    // getters
    PlayerStatus status();

    int floorNbr;
    double timeLeftBeforeDying;

    Backpack *backpack;

private:
    PlayerStatus status_;
};

#endif // PLAYER_H
