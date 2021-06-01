#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "IStorable.h"
#include "IUpgradable.h"
#include "IHasTier.h"

class Equipment : public IStorable, public IUpgradable, public IHasTier
{

};

#endif // EQUIPMENT_H
