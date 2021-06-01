#include "Character.h"
#include "../map/Floor.h"

Character::Character()
{
    for (int i = 0; i < 5; i++)
    {
        this->armorSlots_[i] = NULL;
    }

    for (int i = 0; i < 2; i++)
    {
        this->weaponSlots_[i] = NULL;
    }

    this->inventory_ = new Inventory();
}

int Character::health()
{
    return this->baseHealth;
}

int Character::agility()
{
    return this->baseAgility;
}

int Character::damage()
{
    // base damage + each weapon damage
    int result = this->baseStrength;

    for (int i = 0; i < 2; i++)
    {
        if (this->weaponSlots_[i])
            result += weaponSlots_[i]->damage;
    }

    return result;
}

int Character::armor()
{
    // each armor piece damage
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        if (this->armorSlots_[i])
            result += armorSlots_[i]->protection;
    }

    return result;
}

int Character::posX()
{
    return (int) (this->x() / TILE_SIZE);
}

int Character::posY()
{
    return (int) (this->y() / TILE_SIZE);
}

Inventory *Character::inventory()
{
    return this->inventory_;
}

Armor **Character::armorSlots()
{
    return this->armorSlots_;
}

Weapon **Character::weaponSlots()
{
    return this->weaponSlots_;
}

void Character::posX(int x)
{
    this->setPos(x * TILE_SIZE, y());
}

void Character::posY(int y)
{
    this->setPos(x(), y * TILE_SIZE);
}
