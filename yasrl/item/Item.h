#ifndef ITEM_H
#define ITEM_H

#include "IHasTier.h"
#include "IUpgradable.h"
#include "IStorable.h"

#include <string>
#include <QGraphicsPixmapItem>

enum ItemType
{
    HEAL,
    PAINKILLER,
    VACCINE,
    BACKPACK
};

class Item : public IStorable, public IUpgradable, public IHasTier, public QGraphicsPixmapItem
{
public:
    Item(ItemType type, std::string name);
    ItemType type;
    int effect;
};

#endif // ITEM_H
