#pragma once
#include<memory>

class Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() = 0;
    virtual ~Prototype() = default;
};