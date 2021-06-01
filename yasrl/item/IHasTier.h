#ifndef IHASTIER_H
#define IHASTIER_H

enum Tier
{
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

class IHasTier
{
protected:
    Tier tier;
};

#endif // IHASTIER_H
