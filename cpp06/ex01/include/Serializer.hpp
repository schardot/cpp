#pragma once

#include <cstdint> //in order to use uintptr_t
#include "Data.hpp"

class Serializer
{
private:
    Serializer(/* args */);
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();
public:
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

