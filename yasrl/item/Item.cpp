#include "Item.h"

Item::Item(ItemType type, std::string name)
{
    this->type = type;
    this->size_ = 1;

    // Many ifs because we can't switch case with strings
    switch(type)
    {
    case HEAL:
        if(name == "civilian-medkit")
        {
            this->effect = 25;
            this->setPixmap(QPixmap(":/img/loot/items/civilian-medkit.png"));
        }
        else if(name == "military-medkit")
        {
            this->effect = 50;
            this->setPixmap(QPixmap(":/img/loot/items/military-medkit.png"));
        }
        else if(name == "medical-bottle")
        {
            this->effect = 10;
            this->setPixmap(QPixmap(":/img/loot/items/medical-bottle.png"));
        }
        break;
    case PAINKILLER:
        if(name == "pills")
        {
            this->effect = 15;
            this->setPixmap(QPixmap(":/img/loot/items/pills.png"));
        }
        break;
    case VACCINE:
        if(name == "syringue")
        {
            this->effect = 60;
            this->setPixmap(QPixmap(":/img/loot/items/syringue.png"));
        }
        break;
    case BACKPACK:
        if(name == "city-backpack")
        {
            this->effect = 8;
            this->setPixmap(QPixmap(":/img/loot/backpack/city-backpack.png"));
        }
        else if(name == "duffelbag")
        {
            this->effect = 12;
            this->setPixmap(QPixmap(":/img/loot/backpack/duffelbag.png"));
        }
        else if(name == "military-backpack")
        {
            this->effect = 20;
            this->setPixmap(QPixmap(":/img/loot/backpack/military-backpack.png"));
        }
        break;
    }
}
