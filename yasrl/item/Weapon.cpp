#include "Weapon.h"

Weapon::Weapon(WeaponType type, std::string name)
{
    this->type = type;
    this->size_ = 1;

    // Many ifs because we can't switch case with strings
    switch(type)
    {
    case SMALL:
        if(name == "cleaver")
        {
            this->damage = 5;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/cleaver.png"));
        }
        else if(name == "knife")
        {
            this->damage = 3;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/knife.png"));
        }
        else if(name == "machete")
        {
            this->damage = 7;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/machete.png"));
        }
        else if(name == "pocket-knife-1")
        {
            this->damage = 3;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/pocket-knife-1.png"));
        }
        else if(name == "pocket-knife-2")
        {
            this->damage = 3;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/pocket-knife-2.png"));
        }
        else if(name == "stick")
        {
            this->damage = 2;
            this->setPixmap(QPixmap(":/img/loot/weapons/one-handed/stick.png"));
        }
        break;
    case BIG:
        if(name == "axe")
        {
            this->damage = 9;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/axe.png"));
        }
        else if(name == "baseball-bat")
        {
            this->damage = 6;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/baseball-bat.png"));
        }
        else if(name == "crowbar")
        {
            this->damage = 7;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/crowbar.png"));
        }
        else if(name == "hammer")
        {
            this->damage = 7;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/hammer.png"));
        }
        else if(name == "shovel")
        {
            this->damage = 5;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/shovel.png"));
        }
        else if(name == "wrench")
        {
            this->damage = 6;
            this->setPixmap(QPixmap(":/img/loot/weapons/two-handed/wrench.png"));
        }
        break;
    case SHIELD:
        // No shields currently
        break;
    }
}
