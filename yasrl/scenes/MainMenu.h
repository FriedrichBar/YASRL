#ifndef MAINMENU_H
#define MAINMENU_H

#include "QGraphicsSceneSized.h"

#include <QGraphicsTextItem>
#include <QKeyEvent>

class MainMenu : public QGraphicsSceneSized
{
public:
    // construtor
    MainMenu(QGraphicsView *parent);

    //event management
    void keyPressEvent(QKeyEvent *event);

private:
    // widgets displayed on screen
    QGraphicsTextItem *title;
    QGraphicsTextItem *character0;
    QGraphicsTextItem *quit;
};

#endif // MAINMENU_H
