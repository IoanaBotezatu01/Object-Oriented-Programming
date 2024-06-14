//
// Created by user on 10.05.2023.
//

#include "Car.h"


double Car::computePrice() const {
    if(bodyStyle=="Sedan")
        return this->engine->getPrice()+8000;
    if(bodyStyle=="Convertible")
        return this->engine->getPrice()+9000;
}

Car::Car(std::string bodyStyle, Engine *engine)
{
    this->bodyStyle=bodyStyle;
    this->engine=engine;
}

std::string Car::toString() const
{
    auto price=Car::computePrice();
    auto priceStr=std::to_string(price);
    return "Body style:"+bodyStyle+"; "+engine->toString()+"; Price:"+priceStr;
}
