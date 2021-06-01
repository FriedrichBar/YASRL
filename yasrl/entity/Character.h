#ifndef CHARACTER_H
#define CHARACTER_H

#include "../inventory/Inventory.h"
#include "../item/Armor.h"
#include "../item/Weapon.h"

#include <QGraphicsPixmapItem>

class Character : public QGraphicsPixmapItem
{
public:
    // constructor
    Character();

    // getters
    int health();
    int agility();
    int damage();
    int armor();
    int infectionChance();
    int posX();
    int posY();
    Inventory* inventory();
    Armor** armorSlots();
    Weapon** weaponSlots();

    // setters
    void posX(int x);
    void posY(int y);

    int currentHealth;

protected:
    int baseHealth;
    int baseAgility;
    int baseStrength;
    Inventory* inventory_;
    Armor* armorSlots_[5]; // head, hands, torso, legs, feet
    Weapon* weaponSlots_[2]; // small/big weapon, small weapon/shield
};

#endif // CHARACTER_H
