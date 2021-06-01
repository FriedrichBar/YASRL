#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
// about the different characters

enum EnemyType
{
    KAREN
};

static const struct Karen
{
    static const int baseHealth = 12;
    static const int baseStrength = 12;
    static const int baseAgility = 12;
} karen;

// about the Enemy class

class Enemy : public Character
{
public:
    // constructor
    Enemy(EnemyType type);
};

#endif // ENEMY_H
