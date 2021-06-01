QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game.cpp \
    entity/Character.cpp \
    entity/Enemy.cpp \
    entity/Player.cpp \
    inventory/IStorage.cpp \
    inventory/Inventory.cpp \
    item/Armor.cpp \
    item/IStorable.cpp \
    item/Item.cpp \
    item/Weapon.cpp \
    main.cpp \
    map/Tile.cpp \
    scenes/Exploration.cpp \
    scenes/Fight.cpp \
    scenes/InventoryS.cpp \
    scenes/MainMenu.cpp \
    scenes/QGraphicsSceneSized.cpp \
    map/Floor.cpp

HEADERS += \
    Game.h \
    entity/Character.h \
    entity/Enemy.h \
    entity/Player.h \
    inventory/IStorage.h \
    inventory/Inventory.h \
    item/AllItems.h \
    item/Armor.h \
    item/Backpack.h \
    item/Equipment.h \
    item/IHasTier.h \
    item/IStorable.h \
    item/IUpgradable.h \
    item/Item.h \
    item/Weapon.h \
    map/ChestLootTable.h \
    map/Floor.h \
    map/Skyscraper.h \
    map/Tile.h \
    scenes/Exploration.h \
    scenes/Fight.h \
    scenes/InventoryS.h \
    scenes/MainMenu.h \
    scenes/QGraphicsSceneSized.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
