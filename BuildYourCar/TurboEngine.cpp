//
// Created by user on 10.05.2023.
//

#include "TurboEngine.h"

double TurboEngine::getPrice()
{
    if(this->fuelType=="gasoline")
        return basePrice+0.01*100;
    if(this->fuelType=="diesel")
        return basePrice+0.01*150;
}

std::string TurboEngine::toString()
{
    return "Turbo engine;  Fuel type:"+ this->fuelType;
}

TurboEngine::TurboEngine(std::string fuelType, double basePrice)
{
    this->fuelType=fuelType;
    this->basePrice=basePrice;
}
