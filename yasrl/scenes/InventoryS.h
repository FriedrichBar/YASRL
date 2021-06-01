#ifndef INVENTORYS_H
#define INVENTORYS_H

#include "QGraphicsSceneSized.h"

#include <string>
#include <QGraphicsTextItem>

enum SlotType
{
    ST_WEAPON_1,
    ST_WEAPON_2,
    ST_ARMOR,
    ST_BACKPACK,
    ST_INVENTORY_AVAILABLE,
    ST_INVENTORY_LOCKED
};

class InventoryS : public QGraphicsSceneSized
{
public:
    // constructor
    InventoryS(QGraphicsView *parent);

    // event management
    void keyPressEvent(QKeyEvent *event);

    // dont delete items when deleting scene
    std::vector<QGraphicsPixmapItem*> notToDelete;

private:
    // rendering functions
    void renderNewSlot(int x, int y, SlotType type);
    void renderNewText(int x, int y, std::string text);
    void renderEquipmentBackground();
    void renderEquipment();
    void renderInventoryBackground();
    void renderInventory();
    int iToX(int i, int width);
    int iToY(int i, int width);

    // instruction management
    void addInstrChar(std::string c);
    void rmInstrChar();
    void executeInstr();
    std::string instruction;
    QGraphicsTextItem *instructionDisplay;
};

#endif // INVENTORYS_H
