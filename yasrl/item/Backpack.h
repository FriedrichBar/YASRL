#ifndef BACKPACK_H
#define BACKPACK_H

#include "Item.h"
#include "../inventory/IStorage.h"

class Backpack : public IStorage, public Item
{

};

#endif // BACKPACK_H
