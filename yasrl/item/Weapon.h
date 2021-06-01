#ifndef WEAPON_H
#define WEAPON_H

#include "Equipment.h"

#include <QGraphicsPixmapItem>
#include <string>

enum WeaponType
{
    SMALL,
    BIG,
    SHIELD
};

class Weapon : public Equipment, public QGraphicsPixmapItem
{
public:
    Weapon(WeaponType type, std::string name);
    WeaponType type;
    int damage;
};

#endif // WEAPON_H
