#include "IStorage.h"

#include <vector>
#include <QDebug>

IStorage::IStorage(int baseCapacity, int baseWeightPerSlot)
{
    this->baseCapacity = baseCapacity;
    this->baseWeightPerSlot = baseWeightPerSlot;
}

// manage items

int IStorage::add(IStorable *storable)
{
    // check capacity
    bool capacityOK = this->capacityAvailable() >= storable->size();

    // check weight
    bool weightOK = this->weightAvailable() >= storable->weight();

    // if both are ok then add item and return 0
    if (capacityOK && weightOK)
    {
        this->storage.push_back(storable);
        return 1;
    }
    else
    {
        return 0;
    }
}

IStorage& IStorage::operator+=(IStorable &storable)
{
    this->add(&storable);
    return *this;
}

int IStorage::remove(IStorable *storable)
{
    // search item position
    bool found = false;
    int pos = 0;

    for (auto i = this->getIterator(); i != this->getIteratorEnd(); i++)
    {
        if (*i == storable)
        {
            found = true;
            break;
        }
        pos++;
    }

    // if found, delete it and return 0
    if (found)
    {
        this->storage.erase(this->getIterator() + pos);
        return 0;
    }
    else
    {
        return -1;
    }
}

IStorage& IStorage::operator-=(IStorable &storable)
{
    this->remove(&storable);
    return *this;
}

// get items

std::vector<IStorable*>::iterator IStorage::getIterator()
{
    return this->storage.begin();
}

std::vector<IStorable*>::iterator IStorage::getIteratorEnd()
{
    return this->storage.end();
}

IStorable* IStorage::getItem(int index)
{
    if (index < this->storage.size())
        return this->storage.at(index);
    else
        return NULL;
}

// check status

int IStorage::capacityAvailable()
{
    // sum all items sizes
    int sum = 0;
    for (auto i = this->getIterator(); i != this->getIteratorEnd(); i++)
    {
        sum += (*i)->size();
    }

    // substract to capacity
    return this->capacity() - sum;
}

int IStorage::weightAvailable()
{
    // sum all items weights
    int sum = 0;
    for (auto i = this->getIterator(); i != this->getIteratorEnd(); i++)
    {
        sum += (*i)->weight();
    }

    // substract to max weight
    return this->maxWeight() - sum;
}

int IStorage::nbrThingsStored()
{
    return this->storage.size();
}

// getters

int IStorage::weightPerSlot()
{
    return this->baseWeightPerSlot;
}

int IStorage::capacity()
{
    return this->baseCapacity;
}

int IStorage::maxWeight()
{
    return this->weightPerSlot() * this->capacity();
}
