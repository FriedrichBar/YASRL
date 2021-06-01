#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QString>

enum FloorTheme
{
    DRUGSTORE,
    SUPERMARKET,
    CLOTHING_STORE,
    PUB,
    GYM
};

enum TileType
{
    FLOOR,
    WALL,
    CHEST,
    STAIRS_ASC,
    STAIRS_DSC
};

enum EntitySpawn
{
    NONE,
    PLAYER,
    PLAYER_FROMUP,
    PLAYER_FROMDOWN,
    ENEMY
};

class Tile : public QGraphicsPixmapItem
{
protected:
    TileType type_;
    EntitySpawn entity_;
    bool chestLooted_;
public:
    // Constructor
    Tile(QString stringArray, FloorTheme theme);

    // Getter
    TileType tileType();
    EntitySpawn spawnType();
    int posX();
    int posY();
    bool chestLooted();

    // setter
    void spawnType(EntitySpawn type);
};

struct BadTileException : public std::exception
{
    const char * what () const throw ()
    {
        return "Tile exception : Bad name";
    }
};

#endif // TILE_H
