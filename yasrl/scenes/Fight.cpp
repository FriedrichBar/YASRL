#include "Fight.h"
#include "../Game.h"

#include <QRandomGenerator>
#include <chrono>
#include <QApplication>

#include <QDebug>

extern Game *game;

Fight::Fight(QGraphicsView *parent) : QGraphicsSceneSized(parent)
{
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("YASRL"));
    title->setFont(QFont("Perfect DOS VGA 437", 80));
    title->setPos((parent->width() - 283) / 2, 100);
    title->setDefaultTextColor(QColor(255, 255, 255));
    this->addItem(title);

    QGraphicsTextItem *gameover = new QGraphicsTextItem(QString("GAME OVER"));
    gameover->setFont(QFont("Perfect DOS VGA 437", 100));
    gameover->setPos((parent->width() - 658)/ 2, 290);
    gameover->setDefaultTextColor(QColor(255, 255, 255));
    this->addItem(gameover);

    QGraphicsTextItem *quit = new QGraphicsTextItem(QString("Q > Quit"));
    quit->setFont(QFont("Perfect DOS VGA 437", 40));
    quit->setPos((parent->width() - 233) / 2, 600);
    quit->setDefaultTextColor(QColor(255, 255, 255));
    this->addItem(quit);

    this->setBackgroundBrush(QBrush((Qt::black, Qt::SolidPattern)));
}

void Fight::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        // Q: quits the game
        QApplication::instance()->quit();
        break;
    default:
        qDebug() << "Fight::keyPressEvent unknown key :" << event->key();
    }
}

bool Fight::fightSim(Enemy *enemy)
{
    qDebug() << "##### START FIGHT";
    int seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    QRandomGenerator *gen = new QRandomGenerator(seed);
    gen->bounded(1);

    // positive = player has the best agility = enemy has a chance to miss
    // negative = enemy has the best agility = player has a chance to miss
    double missChance = ((double)game->player->agility() - (double)enemy->agility()) / (double)10;
    // missChance can't be more than 1
    missChance = missChance > 1 ? 1 : missChance;
    missChance = missChance < -1 ? -1 : missChance;

    // most agile hits first
    Character *hisTurn = missChance > 0 ? (Character*)game->player : (Character*)enemy;
    Character *notHisTurn = missChance <= 0 ? (Character*)game->player : (Character*)enemy;

    // if player is the first to play, invert missChance
    missChance = hisTurn == (Character*)game->player ? missChance * -1 : missChance;

    while (game->player->currentHealth > 0 && enemy->currentHealth > 0)
    {
        // hit = (atk - armor) hp lost
        int dmg = hisTurn->damage() - notHisTurn->armor();
        // dmg can't be negative
        dmg = dmg < 0 ? 0 : dmg;

        if (missChance < 0) // there is no chance to miss
        {
            notHisTurn->currentHealth -= dmg;
        }
        else // there is a chance to miss
        {
            double rnd = gen->generateDouble();
            if (rnd > missChance) // not a miss
            {
                notHisTurn->currentHealth -= dmg;
            }
            else
            {
                qDebug() << "FIGHT that's a miss!";
            }
        }

        // switch players
        qDebug() << "FIGHT next turn";
        Character *temp = hisTurn;
        hisTurn = notHisTurn;
        notHisTurn = temp;
        missChance = missChance * -1;
    }

    qDebug() << "FIGHT player HP left =" << game->player->currentHealth;
    return game->player->currentHealth > 0;
}
