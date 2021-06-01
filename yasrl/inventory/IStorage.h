#ifndef ISTORAGE_H
#define ISTORAGE_H

#include "../item/IStorable.h"

#include <vector>

class IStorage
{
public:
    IStorage(int baseCapacity, int baseWeightPerSlot);

    // manage items
    int add(IStorable *storable);
    IStorage& operator+=(IStorable &storable);
    int remove(IStorable *storable);
    IStorage& operator-=(IStorable &storable);

    // get items
    std::vector<IStorable*>::iterator getIterator();
    std::vector<IStorable*>::iterator getIteratorEnd();
    IStorable* getItem(int index);

    // check status
    int capacityAvailable();
    int weightAvailable();
    int nbrThingsStored();

    // getters
    int weightPerSlot();
    int capacity();
    int maxWeight();

protected:
    int baseCapacity;
    int baseWeightPerSlot;
    std::vector<IStorable*> storage;
};

#endif // ISTORAGE_H
