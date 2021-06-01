#include "InventoryS.h"

#include "../Game.h"

#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <sstream>
#include <vector>

#include <QDebug>

extern Game *game;

InventoryS::InventoryS(QGraphicsView *parent) : QGraphicsSceneSized(parent)
{
    this->renderEquipmentBackground();
    this->renderEquipment();

    this->renderInventoryBackground();
    this->renderInventory();

    this->instruction = "";

    this->instructionDisplay = new QGraphicsTextItem();
    this->instructionDisplay->setFont(QFont("Perfect DOS VGA 437", 30));
    this->instructionDisplay->setPos(530, 715);
    this->addItem(this->instructionDisplay);
}

void InventoryS::renderNewSlot(int x, int y, SlotType type)
{
    QString path;
    switch (type)
    {
    case ST_ARMOR:
        path = ":/img/inventory/slot_armor.png";
        break;
    case ST_BACKPACK:
        path = ":/img/inventory/slot_backpack.png";
        break;
    case ST_INVENTORY_AVAILABLE:
        path = ":/img/inventory/slot_inv_available.png";
        break;
    case ST_INVENTORY_LOCKED:
        path = ":/img/inventory/slot_inv_locked.png";
        break;
    case ST_WEAPON_1:
        path = ":/img/inventory/slot_weapon_1.png";
        break;
    case ST_WEAPON_2:
        path = ":/img/inventory/slot_weapon_2.png";
        break;
    }

    QGraphicsPixmapItem *newSlot = new QGraphicsPixmapItem(QPixmap(path));
    newSlot->setPos(x, y);
    this->addItem(newSlot);
}

void InventoryS::renderNewText(int x, int y, std::string text)
{
    QGraphicsTextItem *newText = new QGraphicsTextItem(QString(text.data()));
    newText->setFont(QFont("Perfect DOS VGA 437", 15));
    newText->setPos(x + 80, y + 85);
    this->addItem(newText);
}

void InventoryS::renderEquipmentBackground()
{
    // weapon 1 slot
    this->renderNewSlot(40, 250, ST_WEAPON_1);
    this->renderNewText(40, 250, " 0");
    // weapon 2 slot
    this->renderNewSlot(40, 400, ST_WEAPON_2);
    this->renderNewText(40, 400, " 1");

    // background
    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap(":/img/inventory/guy.png"));
    bg->setPos(200, 32);
    this->addItem(bg);

    // head slot
    this->renderNewSlot(286, 100, ST_ARMOR);
    this->renderNewText(286, 100, " 2");
    // torso slot
    this->renderNewSlot(316, 330, ST_ARMOR);
    this->renderNewText(316, 330, " 3");
    // hands slot
    this->renderNewSlot(196, 450, ST_ARMOR);
    this->renderNewText(196, 450, " 4");
    // legs slot
    this->renderNewSlot(315, 490, ST_ARMOR);
    this->renderNewText(315, 490, " 5");
    // foot slot
    this->renderNewSlot(276, 620, ST_ARMOR);
    this->renderNewText(276, 620, " 6");
}

void InventoryS::renderEquipment()
{
    Armor** armorSlots = game->player->armorSlots();
    if (armorSlots[0])
    {
        this->addItem(armorSlots[0]);
        armorSlots[0]->setPos(286, 100);
        this->notToDelete.push_back(armorSlots[0]);
    }
    if (armorSlots[1])
    {
        this->addItem(armorSlots[1]);
        armorSlots[1]->setPos(196, 450);
        this->notToDelete.push_back(armorSlots[1]);
    }
    if (armorSlots[2])
    {
        this->addItem(armorSlots[2]);
        armorSlots[2]->setPos(316, 330);
        this->notToDelete.push_back(armorSlots[2]);
    }
    if (armorSlots[3])
    {
        this->addItem(armorSlots[3]);
        armorSlots[3]->setPos(315, 490);
        this->notToDelete.push_back(armorSlots[3]);
    }
    if (armorSlots[4])
    {
        this->addItem(armorSlots[4]);
        armorSlots[4]->setPos(276, 620);
        this->notToDelete.push_back(armorSlots[4]);
    }

    Weapon** weaponSlots = game->player->weaponSlots();
    if (weaponSlots[0])
    {
        this->addItem(weaponSlots[0]);
        weaponSlots[0]->setPos(40, 250);
        this->notToDelete.push_back(weaponSlots[0]);
    }
    if (weaponSlots[1])
    {
        this->addItem(weaponSlots[1]);
        weaponSlots[1]->setPos(40, 400);
        this->notToDelete.push_back(weaponSlots[1]);
    }
}

int InventoryS::iToX(int i, int width)
{
    return i % width;
}

int InventoryS::iToY(int i, int width)
{
    return (i - iToX(i, width) ) / width;
}

void InventoryS::renderInventoryBackground()
{
    // backpack slot
    this->renderNewSlot(590, 325, ST_BACKPACK);
    this->renderNewText(590, 325, " 7");

    // slot grid, 4 width, 6 height
    int nbrSlotsEnabled = game->player->inventory()->capacity();
    if (game->player->backpack)
    {
        nbrSlotsEnabled += game->player->backpack->capacity();
    }

    int offsetX = 745, offsetY = 15;
    int gap = 125;
    for (int i = 0; i < 4 * 6; i++)
    {
        int x = offsetX + this->iToX(i, 4) * gap;
        int y = offsetY + this->iToY(i, 4) * gap;

        if (i < nbrSlotsEnabled)
            this->renderNewSlot(x, y, ST_INVENTORY_AVAILABLE);
        else
            this->renderNewSlot(x, y, ST_INVENTORY_LOCKED);
        this->renderNewText(x, y, QString::number(10 + i).toStdString());
    }
}

void InventoryS::renderInventory()
{
    int offsetX = 745, offsetY = 15, gap = 125, index = 0;
    for (auto it = game->player->inventory()->getIterator(); it != game->player->inventory()->getIteratorEnd(); it++)
    {
        IStorable* itemS = *it;

        if (Armor* a = dynamic_cast<Armor*>(itemS))
        {
            this->addItem(a);
            a->setPos(offsetX + index * gap, offsetY);
            this->notToDelete.push_back(a);
        }
        else if (Weapon* w = dynamic_cast<Weapon*>(itemS))
        {
            this->addItem(w);
            w->setPos(offsetX + index * gap, offsetY);
            this->notToDelete.push_back(w);
        }
        else if (Item* i = dynamic_cast<Item*>(itemS))
        {
            this->addItem(i);
            i->setPos(offsetX + index * gap, offsetY);
            this->notToDelete.push_back(i);
        }
        else
        {
            qDebug() << "InventoryS::renderInventory() item not recognized";
        }

        index++;
    }
}

void InventoryS::addInstrChar(std::string c)
{
    this->instruction.append(c);
    this->instructionDisplay->setPlainText(QString(this->instruction.data()));
}

void InventoryS::rmInstrChar()
{
    if (this->instruction.length() > 0)
    {
        this->instruction = this->instruction.substr(0, this->instruction.length() - 1);
        this->instructionDisplay->setPlainText(QString(this->instruction.data()));
    }
}

void InventoryS::executeInstr()
{
    // split instruction by space
    QString qinstruction = QString(this->instruction.data());
    qinstruction = qinstruction.simplified();
    QStringList instrSplit = qinstruction.split(' ');

    // if RM
    if (instrSplit[0] == "RM")
    {
        // remove item from inventory
        int index = instrSplit[1].toInt();

        // is a weapon
        if (index == 0 || index == 1)
            game->player->weaponSlots()[index] = NULL;
        // is an armor piece
        else if (index >= 2 && index <= 6)
            game->player->armorSlots()[index - 2] = NULL;
        // is the backpack
        else if (index == 7)
            game->player->backpack = NULL;
        // is in the inventory
        else if (index >= 10 && index <= 13)
            game->player->inventory()->remove(game->player->inventory()->getItem(index - 10));
        // is in the backpack
        else if (index >= 14 && index <= 33 && game->player->backpack != NULL)
            game->player->backpack->remove(game->player->backpack->getItem(index - 14));

        // update inventory display
        game->displayInventory();
    }
    // if EQ
    else if (instrSplit[0] == "EQ")
    {
        // item has to be in inventory
        int index = instrSplit[1].toInt();
        if (index >= 10  && index <= 13)
        {
            IStorable *item = game->player->inventory()->getItem(index - 10);

            // if weapon
            if (Weapon* w = dynamic_cast<Weapon*>(item))
            {
                if (game->player->weaponSlots()[0] != NULL && game->player->weaponSlots()[1] == NULL)
                {
                    game->player->weaponSlots()[1] = w;
                }
                else
                {
                    game->player->weaponSlots()[0] = w;
                }
                game->player->inventory()->remove(item);
            }
            // if armor piece
            else if (Armor* a = dynamic_cast<Armor*>(item))
            {
                ArmorType type = a->type;
                // head, hands, torso, legs, feet
                switch (type)
                {
                case HEAD:
                    game->player->armorSlots()[0] = a;
                    break;
                case HANDS:
                    game->player->armorSlots()[1] = a;
                    break;
                case BODY:
                    game->player->armorSlots()[2] = a;
                    break;
                case LEGS:
                    game->player->armorSlots()[3] = a;
                    break;
                case FEET:
                    game->player->armorSlots()[4] = a;
                    break;
                }
                game->player->inventory()->remove(item);
            }
            // if backpack
            else if (Backpack* b = dynamic_cast<Backpack*>(item))
            {
                game->player->backpack = b;
                game->player->inventory()->remove(item);
            }
        }

        // update inventory display
        game->displayInventory();
    }
    // if USE
    else if (instrSplit[0] == "USE")
    {
        // has to be in the inventory
        int index = instrSplit[1].toInt();
        if (index >= 10 && index <= 13)
        {
            IStorable *itemS = game->player->inventory()->getItem(index - 10);
            if (itemS)
            {
                // has to be an item
                if (Item* item = dynamic_cast<Item*>(itemS))
                {
                    switch (item->type)
                    {
                    case HEAL:
                        int currentHealth = game->player->currentHealth;
                        int maxHealth = game->player->health();
                        if (currentHealth + item->effect >= maxHealth)
                            game->player->currentHealth = maxHealth;
                        else
                            game->player->currentHealth = currentHealth + item->effect;
                        break;
                    }
                    game->player->inventory()->remove(item);
                }
            }
        }

        // update inventory display
        game->displayInventory();
    }
    else
    {
        qDebug() << "InventoryS::executeInstr instruction not recognized :" << instrSplit[0];
        game->displayInventory();
    }
}

void InventoryS::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Tab:
        game->displayExploration();
        break;
    case Qt::Key_Backspace:
        this->rmInstrChar();
        break;
    case Qt::Key_Space:
        this->addInstrChar(" ");
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        this->executeInstr();
        break;
    case Qt::Key_M:
        this->addInstrChar("M");
        break;
    case Qt::Key_R:
        this->addInstrChar("R");
        break;
    case Qt::Key_U:
        this->addInstrChar("U");
        break;
    case Qt::Key_S:
        this->addInstrChar("S");
        break;
    case Qt::Key_E:
        this->addInstrChar("E");
        break;
    case Qt::Key_Q:
        this->addInstrChar("Q");
        break;
    case Qt::Key_0:
        this->addInstrChar("0");
        break;
    case Qt::Key_1:
        this->addInstrChar("1");
        break;
    case Qt::Key_2:
        this->addInstrChar("2");
        break;
    case Qt::Key_3:
        this->addInstrChar("3");
        break;
    case Qt::Key_4:
        this->addInstrChar("4");
        break;
    case Qt::Key_5:
        this->addInstrChar("5");
        break;
    case Qt::Key_6:
        this->addInstrChar("6");
        break;
    case Qt::Key_7:
        this->addInstrChar("7");
        break;
    case Qt::Key_8:
        this->addInstrChar("8");
        break;
    case Qt::Key_9:
        this->addInstrChar("9");
        break;
    default:
        qDebug() << "InventoryS::keyPressEvent unknown key :" << event->key();
    }
}
