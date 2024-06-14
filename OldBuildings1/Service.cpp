//
// Created by user on 10.05.2023.
//

#include "Service.h"

void Service::addBuilding(Building *b)
{
    buildings.push_back(b);
}

std::vector<Building *> Service::getAllBuildings()
{

    return this->buildings;
}

std::vector<Building *> Service::getAllToBeRestored() {
    this->selectRestored();
    return this->restored;
}

std::vector<Building *> Service::getAllToBeDemolished() {
    this->selectDemolish();
    return this->demolished;
}

void Service::selectRestored()
{
    for(auto i:buildings)
        if(i->mustBeRestored())
            restored.push_back(i);
}

void Service::selectDemolish()
{
for(auto i:buildings)
    if(i->canBeDemolished())
        demolished.push_back(i);
}
