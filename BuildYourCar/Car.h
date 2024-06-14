//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_CAR_H
#define BUILDYOURCAR_CAR_H
#include "string"
#include "Engine.h"

class Car {
private:
    std::string bodyStyle;
    Engine* engine;
public:
    Car(std::string bodyStyle,Engine* engine);
    std::string toString() const;
    double computePrice() const;

};


#endif //BUILDYOURCAR_CAR_H
