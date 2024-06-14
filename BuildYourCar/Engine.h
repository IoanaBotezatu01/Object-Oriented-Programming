//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_ENGINE_H
#define BUILDYOURCAR_ENGINE_H
#include "string"

class Engine {
protected:
    std::string fuelType;
    double basePrice=3000;
public:
    Engine()=default;
    virtual ~Engine() {};
    virtual double getPrice()=0;

    virtual std::string toString()=0;

};


#endif //BUILDYOURCAR_ENGINE_H
