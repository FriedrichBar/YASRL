#include "Tile.h"

#include <QRegularExpression>
#include <QDebug>

Tile::Tile(QString stringArray, FloorTheme theme)
{
    try
    {
        // Getting the first character of our string
        int firstChar = stringArray.at(0).toLatin1();
        // if the character is invalid
        if(firstChar != '.' && firstChar != '|' && firstChar != '#' && firstChar != 'x' && firstChar != '=' && firstChar != '+')
            // we throw an exception
            throw BadTileException();

        // Array for floors names
        QString floors[5] = {"Ds", "Sm", "Cs", "Pub", "Gym"};

        QString pathToImg = ":/img/map/";

        switch(firstChar)
        {
        // Floor
        case '.':
            this->type_ = FLOOR;
            this->entity_ = NONE;
            pathToImg.append(floors[theme] + "/floor");
            break;
        // Player
        case '|':
            this->type_ = FLOOR;
            this->entity_ = PLAYER;
            pathToImg.append(floors[theme] + "/floor");
            break;
        // Enemy
        case '#':
            this->type_ = FLOOR;
            this->entity_ = ENEMY;
            pathToImg.append(floors[theme] + "/floor");
            break;
        // Wall
        case 'x':
            this->type_ = WALL;
            this->entity_ = NONE;
            pathToImg.append(floors[theme] + "/wall" + stringArray.remove(0,1));
            break;
        // Chest
        case '=':
            this->type_ = CHEST;
            this->entity_ = NONE;
            this->chestLooted_ = false;
            pathToImg.append(floors[theme] + "/chest");
            break;
        // Stairs
        case '+':
            if(stringArray.remove(0,1).left(4) == "Exit") // if it's an exit
            {
                this->type_ = STAIRS_DSC;
                this->entity_ = PLAYER_FROMDOWN; // spawnpoint for player when going up
            }
            else
            {
                this->type_ = STAIRS_ASC;
                this->entity_ = PLAYER_FROMUP; // spawnpoint for player when going down
            }
            pathToImg.append(floors[theme] + "/stairsE" + stringArray.remove(0,1));
            break;
        }
        pathToImg.append(".png");

        this->setPixmap(QPixmap(pathToImg));
    }
    catch(BadTileException& e)
    {
        qDebug() << e.what();
    }
}

// getters

TileType Tile::tileType()
{
    return this->type_;
}

EntitySpawn Tile::spawnType()
{
    return this->entity_;
}

int Tile::posX()
{
    return (int)this->x() / 64;
}

int Tile::posY()
{
    return (int)this->y() / 64;
}

bool Tile::chestLooted()
{
    return this->chestLooted_;
}

void Tile::spawnType(EntitySpawn type)
{
    this->entity_ = type;
}
