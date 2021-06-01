#include "Enemy.h"

Enemy::Enemy(EnemyType type)
{
    // set base stats
    switch (type)
    {
    case KAREN:
        this->baseHealth = karen.baseHealth;
        this->baseStrength = karen.baseStrength;
        this->baseAgility = karen.baseAgility;
        this->setPixmap(QPixmap(":/img/enemies/karen.png"));
    }

    this->currentHealth = this->baseHealth;
}
