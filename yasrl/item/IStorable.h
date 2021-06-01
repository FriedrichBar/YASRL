#ifndef ISTORABLE_H
#define ISTORABLE_H

#include <string>

class IStorable
{
public:
    int size();
    int weight();

    virtual ~IStorable() = default; // just to make it polymorphic

    static IStorable* getItemInstance(std::string name);
protected:
    int size_;
    int weight_;
};

#endif // ISTORABLE_H
