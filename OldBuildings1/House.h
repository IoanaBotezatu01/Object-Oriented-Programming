//
// Created by user on 10.05.2023.
//

#ifndef OLDBUILDINGS1_HOUSE_H
#define OLDBUILDINGS1_HOUSE_H
#include "Building.h"

class House :public Building{
private:
    bool isHistorical;
public:
    explicit House(std::string address,int constructionYear,bool isHistorical);
    bool mustBeRestored() override;
    bool canBeDemolished() override;
    std::string toString() override;

};


#endif //OLDBUILDINGS1_HOUSE_H
