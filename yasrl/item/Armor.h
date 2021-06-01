#ifndef ARMOR_H
#define ARMOR_H

#include "Equipment.h"

#include <string>
#include <QGraphicsPixmapItem>

enum ArmorType
{
    HEAD,
    BODY,
    LEGS,
    HANDS,
    FEET
};

class Armor : public Equipment, public QGraphicsPixmapItem
{
public:
    Armor(ArmorType type, std::string name);
    ArmorType type;
    int protection;
};

#endif // ARMOR_H
