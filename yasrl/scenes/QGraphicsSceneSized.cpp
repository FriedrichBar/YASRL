#include "QGraphicsSceneSized.h"

QGraphicsSceneSized::QGraphicsSceneSized(QGraphicsView *parent)
{
    this->setSceneRect(0, 0, parent->width(), parent->height());
}
