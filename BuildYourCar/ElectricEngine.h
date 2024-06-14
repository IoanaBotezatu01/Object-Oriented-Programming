//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_ELECTRICENGINE_H
#define BUILDYOURCAR_ELECTRICENGINE_H
#include "Engine.h"

class ElectricEngine : public  Engine{
private:
    int autonomy;
public:
    ElectricEngine()=default;
    ElectricEngine(int autonomy,double basePrice);
    double getPrice() override;
    std::string toString() override;
};


#endif //BUILDYOURCAR_ELECTRICENGINE_H
