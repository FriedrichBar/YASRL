#include "Armor.h"

Armor::Armor(ArmorType type, std::string name)
{
    this->type = type;
    this->size_ = 1;

    // Many ifs because we can't switch case with strings
    switch(type)
    {
    case HEAD:
        if(name == "beanie")
        {
            this->protection = 2;
            this->setPixmap(QPixmap(":/img/loot/head/beanie.png"));
        }
        else if(name == "crocodile-hat")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/head/crocodile-hat.png"));
        }
        else if(name == "hijab")
        {
            this->protection = 2;
            this->setPixmap(QPixmap(":/img/loot/head/hijab.png"));
        }
        else if(name == "hockey-mask")
        {
            this->protection = 4;
            this->setPixmap(QPixmap(":/img/loot/head/hockey-mask.png"));
        }
        else if(name == "military-cap")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/head/military-cap.png"));
        }
        else if(name == "military-helmet")
        {
            this->protection = 10;
            this->setPixmap(QPixmap(":/img/loot/head/military-helmet"));
        }
        else if(name == "motorcycle-helmet")
        {
            this->protection = 7;
            this->setPixmap(QPixmap(":/img/loot/head/motorcycle-helmet.png"));
        }
        else if(name == "riot-helmet")
        {
            this->protection = 8;
            this->setPixmap(QPixmap(":/img/loot/head/riot-helmet"));
        }
        else if(name == "surgical-mask")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/head/surgical-mask"));
        }
        else if(name == "worker-helmet")
        {
            this->protection = 6;
            this->setPixmap(QPixmap(":/img/loot/head/worker-helmet.png"));
        }
        break;
    case BODY:
        if(name == "body-armor-1")
        {
            this->protection = 10;
            this->setPixmap(QPixmap(":/img/loot/torso/body-armor-1.png"));
        }
        else if(name == "body-armor-2")
        {
            this->protection = 9;
            this->setPixmap(QPixmap(":/img/loot/torso/body-armor-2.png"));
        }
        else if(name == "coat")
        {
            this->protection = 4;
            this->setPixmap(QPixmap(":/img/loot/torso/coat.png"));
        }
        else if(name == "hunter-coat")
        {
            this->protection = 5;
            this->setPixmap(QPixmap(":/img/loot/torso/hunter-coat.png"));
        }
        else if(name == "motorcycle-armor")
        {
            this->protection = 8;
            this->setPixmap(QPixmap(":/img/loot/torso/motorcycle-armor.png"));
        }
        else if(name == "motorcycle-vest-1")
        {
            this->protection = 7;
            this->setPixmap(QPixmap(":/img/loot/torso/motorcycle-vest-1.png"));
        }
        else if(name == "motorcycle-vest-2")
        {
            this->protection = 7;
            this->setPixmap(QPixmap(":/img/loot/torso/motorcycle-vest-2.png"));
        }
        else if(name == "nbc-vest")
        {
            this->protection = 4;
            this->setPixmap(QPixmap(":/img/loot/torso/nbc-vest.png"));
        }
        else if(name == "tshirt")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/torso/tshirt.png"));
        }
        break;
    case LEGS:
        if(name == "boxers")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/legs/boxers.png"));
        }
        else if(name == "cargo-pants")
        {
            this->protection = 4;
            this->setPixmap(QPixmap(":/img/loot/legs/cargo-pants.png"));
        }
        else if(name == "leggings")
        {
            this->protection = 2;
            this->setPixmap(QPixmap(":/img/loot/legs/leggings.png"));
        }
        else if(name == "military-pants")
        {
            this->protection = 6;
            this->setPixmap(QPixmap(":/img/loot/legs/military-pants.png"));
        }
        else if(name == "shorts")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/legs/shorts.png"));
        }
        break;
    case HANDS:
        if(name == "punk-gloves")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/hands/punk-gloves.png"));
        }
        else if(name == "rubber-gloves")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/hands/rubber-gloves.png"));
        }
        break;
    case FEET:
        if(name == "biker-boots")
        {
            this->protection = 5;
            this->setPixmap(QPixmap(":/img/loot/feet/biker-boots.png"));
        }
        else if(name == "civilian-boots")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/feet/civilian-boots.png"));
        }
        else if(name == "desert-rangers")
        {
            this->protection = 6;
            this->setPixmap(QPixmap(":/img/loot/feet/desert-rangers.png"));
        }
        else if(name == "flippers")
        {
            this->protection = 1;
            this->setPixmap(QPixmap(":/img/loot/feet/flippers.png"));
        }
        else if(name == "nbc-boots")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/feet/nbc-boots.png"));
        }
        else if(name == "rangers")
        {
            this->protection = 5;
            this->setPixmap(QPixmap(":/img/loot/feet/rangers.png"));
        }
        else if(name == "rubber-boots")
        {
            this->protection = 3;
            this->setPixmap(QPixmap(":/img/loot/feet/rubber-boots.png"));
        }
        else if(name == "sandals")
        {
            this->protection = 2;
            this->setPixmap(QPixmap(":/img/loot/feet/sandals.png"));
        }
        break;
    }
}
