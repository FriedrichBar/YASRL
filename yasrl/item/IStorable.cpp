#include "IStorable.h"
#include "AllItems.h"
#include "Armor.h"
#include "Weapon.h"
#include "Item.h"

int IStorable::size()
{
    return this->size_;
}

int IStorable::weight()
{
    return this->weight_;
}

IStorable *IStorable::getItemInstance(std::string name)
{
    if(std::find(std::begin(allArmors), std::end(allArmors), name) != std::end(allArmors)) // if it's an armor
    {
        Armor *newArmor;
        if(std::distance(std::begin(allArmors), std::find(std::begin(allArmors), std::end(allArmors), name)) <= 9)
            newArmor = new Armor(HEAD, name);
        else if(std::distance(std::begin(allArmors), std::find(std::begin(allArmors), std::end(allArmors), name)) <= 18)
            newArmor = new Armor(BODY, name);
        else if(std::distance(std::begin(allArmors), std::find(std::begin(allArmors), std::end(allArmors), name)) <= 23)
            newArmor = new Armor(LEGS, name);
        else if(std::distance(std::begin(allArmors), std::find(std::begin(allArmors), std::end(allArmors), name)) <= 31)
            newArmor = new Armor(FEET, name);
        else
            newArmor = new Armor(HANDS, name);
        return (IStorable*) newArmor;
    }
    else if(std::find(std::begin(allWeapons), std::end(allWeapons), name) != std::end(allWeapons)) // if it's a weapon
    {
        Weapon *newWeapon;
        if(std::distance(std::begin(allWeapons), std::find(std::begin(allWeapons), std::end(allWeapons), name)) <= 5)
            newWeapon = new Weapon(SMALL, name);
        else
            newWeapon = new Weapon(BIG, name);
        return (IStorable*) newWeapon;
    }
    else if(std::find(std::begin(allItems), std::end(allItems), name) != std::end(allItems)) // if it's an item
    {
        Item *newItem;
        if(std::distance(std::begin(allItems), std::find(std::begin(allItems), std::end(allItems), name)) <= 2)
            newItem = new Item(HEAL, name);
        else if(std::distance(std::begin(allItems), std::find(std::begin(allItems), std::end(allItems), name)) == 3)
            newItem = new Item(PAINKILLER, name);
        else
            newItem = new Item(VACCINE, name);
        return (IStorable*) newItem;
    }
    else
        return NULL;
}
