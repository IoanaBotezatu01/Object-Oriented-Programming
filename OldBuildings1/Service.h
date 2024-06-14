//
// Created by user on 10.05.2023.
//

#ifndef OLDBUILDINGS1_SERVICE_H
#define OLDBUILDINGS1_SERVICE_H
#include "Building.h"
#include "Block.h"
#include "House.h"
#include "vector"

class Service {
private:
    std::vector<Building*> buildings;
    std::vector<Building*> restored;
    std::vector<Building*> demolished;
public:
    void addBuilding(Building* b);
    std::vector<Building*> getAllBuildings();
    std::vector<Building*> getAllToBeRestored();
    std::vector<Building*> getAllToBeDemolished();
    void writeToFile(std::string filename,std::vector<Building*>buildings);
    void selectRestored();
    void selectDemolish();
};


#endif //OLDBUILDINGS1_SERVICE_H
