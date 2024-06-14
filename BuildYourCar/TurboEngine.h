//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_TURBOENGINE_H
#define BUILDYOURCAR_TURBOENGINE_H
#include "string"
#include "Engine.h"

class TurboEngine: public Engine{
public:
    TurboEngine()=default;
    TurboEngine(std::string fuelType,double basePrice) ;
    double getPrice() override;
    std::string toString() override;
};


#endif //BUILDYOURCAR_TURBOENGINE_H
