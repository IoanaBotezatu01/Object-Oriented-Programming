//
// Created by user on 10.05.2023.
//

#ifndef OLDBUILDINGS1_BLOCK_H
#define OLDBUILDINGS1_BLOCK_H
#include "Building.h"


class Block: public Building{
private:
    int totalApartments;
    int occupiedApartments;
public:
    Block(std::string address,int constructionYear,int totalApartments,int occupiedApartments);
    bool mustBeRestored() override;
    bool canBeDemolished() override;
    std::string toString() override;
};


#endif //OLDBUILDINGS1_BLOCK_H
