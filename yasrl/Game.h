#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "scenes/MainMenu.h"
#include "scenes/Exploration.h"
#include "scenes/Fight.h"
#include "scenes/InventoryS.h"
#include "entity/Player.h"

const int TPS = 60;

enum GameStatus
{
    MAINMENU,
    EXPLORATION,
    FIGHT,
    INVENTORY
};

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    // constructor
    Game();

    // event management
    void keyPressEvent(QKeyEvent *event);

    // scene management
    void displayMainMenu();
    void displayExploration();
    void displayFight();
    void displayInventory();

    // game data
    GameStatus status;
    Player *player;

    // getters
    Exploration* exploration();

public slots:
    // tick management
    void tick();

private:
    // scenes
    MainMenu *mainMenu;
    Exploration *exploration_;
    Fight *fight;
    InventoryS *inventory;
};

#endif // GAME_H
