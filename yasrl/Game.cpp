#include "Game.h"

#include <QApplication>
#include <QTimer>

Game::Game()
{
    // set QView properties
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(1280, 768);

    // instanciate all the QScenes
    this->mainMenu = new MainMenu(this);
    this->exploration_ = new Exploration(this);
    this->fight = new Fight(this);
    // not inventory since it has to be re-built every time
    this->inventory = NULL;

    // game default state
    this->show();
    this->displayMainMenu();

    // start ticking
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(1000 / TPS);
}

// tick management

void Game::tick()
{
    if (this->status == EXPLORATION)
    {
        this->player->move();
    }
}

// scene management

void Game::displayMainMenu()
{
    this->setScene(mainMenu);
    this->status = MAINMENU;
}

void Game::displayExploration()
{
    this->exploration()->renderFloor(this->player->floorNbr);
    this->setScene(this->exploration());
    this->status = EXPLORATION;
}

void Game::displayFight()
{
    this->setScene(this->fight);
    this->status = FIGHT;
}

void Game::displayInventory()
{
    if (this->inventory)
    {
        for (auto it = this->inventory->notToDelete.begin(); it != this->inventory->notToDelete.end(); it++)
        {
            QGraphicsPixmapItem* item = *it;
            this->inventory->removeItem(item);
        }

        delete(this->inventory);
    }
    this->inventory = new InventoryS(this);
    this->setScene(this->inventory);
    this->status = INVENTORY;
}

Exploration *Game::exploration()
{
    return this->exploration_;
}

// event handling

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (this->status)
    {
    case MAINMENU:
        this->mainMenu->keyPressEvent(event);
        break;
    case EXPLORATION:
        this->exploration()->keyPressEvent(event);
        break;
    case FIGHT:
        this->fight->keyPressEvent(event);
        break;
    case INVENTORY:
        this->inventory->keyPressEvent(event);
        break;
    }
}
