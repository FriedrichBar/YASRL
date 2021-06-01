#include "MainMenu.h"
#include "../Game.h"
#include "../entity/Player.h"

#include <QApplication>

extern Game *game;

MainMenu::MainMenu(QGraphicsView *parent) : QGraphicsSceneSized(parent)
{
    title = new QGraphicsTextItem(QString("YASRL"));
    title->setFont(QFont("Perfect DOS VGA 437", 80));
    title->setPos((parent->width() - 283) / 2, 100);
    this->addItem(title);

    character0 = new QGraphicsTextItem(QString("0 > Play Mr. Nobody"));
    character0->setFont(QFont("Perfect DOS VGA 437", 40));
    character0->setPos((parent->width() - 562) / 2, 290);
    this->addItem(character0);

    quit = new QGraphicsTextItem(QString("Q > Quit"));
    quit->setFont(QFont("Perfect DOS VGA 437", 40));
    quit->setPos((parent->width() - 233) / 2, 600);
    this->addItem(quit);
}

void MainMenu::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        // Q: quits the game
        QApplication::instance()->quit();
        break;
    case Qt::Key_0:
        // 0: starts exploration with Mr. Nobody
        game->player = new Player(MR_NOBODY);
        game->displayExploration();
        break;
    default:
        qDebug() << "MainMenu::keyPressEvent unknown key :" << event->key();
    }
}
