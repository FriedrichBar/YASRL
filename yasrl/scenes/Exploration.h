#ifndef EXPLORATION_H
#define EXPLORATION_H

#include "QGraphicsSceneSized.h"
#include "../map/Floor.h"

#include <QKeyEvent>

class Exploration : public QGraphicsSceneSized
{
public:
    // constructor
    Exploration(QGraphicsView *parent);

    // level rendering
    void renderFloor(int lvl);

    // event management
    void keyPressEvent(QKeyEvent *event);
    void actionKeyHandler();

    // getters
    Floor* currentFloor();

private:
    Floor *currentFloor_;
    Floor *renderedFloors[16];
};

#endif // EXPLORATION_H
