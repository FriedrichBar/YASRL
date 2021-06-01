#ifndef CHESTLOOTTABLE_H
#define CHESTLOOTTABLE_H

#include <string>

// values in "chancesX" are probabilities from 0 to 1
// strings in "itemsX" are the same exact strings taken by Armor, Item and Weapon in their constructors

// loot table for DRUGSTORE
const int size1 = 11;
const double chances1[] = {0.10, 0.50, 0.05, 0.05, 0.20, 0.20, 0.40, 0.30, 0.10, 0.50, 0.30}; // must be <= 3
const std::string items1[] = {"knife", "surgical-mask", "nbc-vest", "nbc-boots", "rubber-boots", "rubber-gloves",
                              "civilian-medkit", "medical-bottle", "military-medkit", "pills", "syringue"};

// loot table for SUPERMARKET
const int size2 = 12;
const double chances2[] = {0.05, 0.10, 0.30, 0.60, 0.012, 0.15, 0.015, 0.35, 0.40, 0.40, 0.30, 0.10}; // must be <= 3
const std::string items2[] = {"civilian-medkit", "medical-bottle", "cleaver", "knife", "axe", "hammer",
                              "shovel", "wrench", "boxers", "leggings", "shorts", "cargo-pants"};

// loot table for CLOTHING_STORE
const int size3 = 13;
const double chances3[] = {0.10, 0.25, 0.05, 0.25, 0.30, 0.12, 0.15, 0.20, 0.20, 0.35, 0.30, 0.25, 0.08}; // must be <= 3
const std::string items3[] = {"civilian-boots", "flippers", "rangers", "sandals", "beanie", "hijab",
                              "military-cap", "coat", "tshirt", "boxers", "leggings", "shorts",
                              "cargo-pants"};

// loot table for PUB
const int size4 = 22;
const double chances4[] = {0.10, 0.05, 0.10, 0.10, 0.20, 0.10, 0.08, 0.05, 0.10, 0.20, 0.05, 0.08, 0.08, 0.12, 0.10, 0.15, 0.10, 0.15, 0.10, 0.10, 0.25, 0.05}; // must be <= 3
const std::string items4[] = {"knife", "machete", "pocket-knife-1", "pocket-knife-2", "baseball-bat", "crowbar",
                              "wrench", "motorcycle-helmet", "worker-helmet", "coat", "motorcycle-armor",
                              "motorcycle-vest-1", "motorcycle-vest-2", "cargo-pants", "shorts", "punk-gloves",
                              "biker-boots", "rangers", "desert-rangers", "civilian-medkit", "pills", "syringue"};

// loot table for GYM
const int size5 = 15;
const double chances5[] = {0.10, 0.10, 0.10, 0.15, 0.20, 0.05, 0.05, 0.10, 0.25, 0.10, 0.30, 0.30, 0.20, 0.30, 0.20}; // must be <= 3
const std::string items5[] = {"knife", "pocket-knife-1", "pocket-knife-2", "stick", "baseball-bat", "crowbar", "wrench",
                              "crocodile-hat", "hockey-mask", "military-cap", "tshirt", "boxers", "shorts", "leggings",
                              "civilian-boots"};

// TESTING LOOT TABLE
const int sizeT = 1;
const double chancesT[] = {1};
const std::string itemsT[] = {"medical-bottle"};

// loot tables are in the same order as FloorTheme in Tile.h
const int lootSize[] = {size1, size2, size3, size4, size5};
const double* lootChances[] = {chances1, chances2, chances3, chances4, chances5};
const std::string* lootItems[] = {items1, items2, items3, items4, items5};

#endif // CHESTLOOTTABLE_H
