#ifndef FIGHT_H
#define FIGHT_H

#include "QGraphicsSceneSized.h"
#include "../entity/Enemy.h"

#include <QKeyEvent>

class Fight : public QGraphicsSceneSized
{
public:
    // constructor
    Fight(QGraphicsView *parent);

    // event management
    void keyPressEvent(QKeyEvent *event);

    static bool fightSim(Enemy *enemy);
};

#endif // FIGHT_H
