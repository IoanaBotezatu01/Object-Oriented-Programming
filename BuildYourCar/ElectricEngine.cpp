//
// Created by user on 10.05.2023.
//

#include "ElectricEngine.h"

std::string ElectricEngine::toString()
{
    auto autonomyStr=std::to_string(autonomy);
    auto basePriceStr=std::to_string(basePrice);
    return " Electric engine;   Autonomy:"+autonomyStr;
}

double ElectricEngine::getPrice()
{
    return basePrice+autonomy*0.01;
}

ElectricEngine::ElectricEngine(int autonomy, double basePrice)  {
    this->autonomy=autonomy;
    this->fuelType="";
    this->basePrice=basePrice;
}
