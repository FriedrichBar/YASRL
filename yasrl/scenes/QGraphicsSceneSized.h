#ifndef QGRAPHICSSCENESIZED_H
#define QGRAPHICSSCENESIZED_H

#include <QGraphicsView>
#include <QGraphicsScene>

class QGraphicsSceneSized : public QGraphicsScene
{
public:
    // constructor
    QGraphicsSceneSized(QGraphicsView *parent);
};

#endif // QGRAPHICSSCENESIZED_H
