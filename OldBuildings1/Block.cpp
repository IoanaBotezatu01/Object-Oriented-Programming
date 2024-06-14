//
// Created by user on 10.05.2023.
//

#include "Block.h"

Block::Block(std::string address, int constructionYear, int totalApartments, int occupiedApartments) {
    this->address=address;
    this->constructionYear=constructionYear;
    this->totalApartments=totalApartments;
    this->occupiedApartments=occupiedApartments;
}

bool Block::mustBeRestored() {
    if(2023-constructionYear>40 && this->occupiedApartments>0.8* this->totalApartments)
        return true;
    else
        return false;
}

bool Block::canBeDemolished() {
    if(this->occupiedApartments<0.05* this->totalApartments)
        return true;
    else
        return false;
}

std::string Block::toString() {
    auto yearStr=std::to_string(constructionYear);
    auto totalStr=std::to_string(totalApartments);
    auto occupiedStr=std::to_string(occupiedApartments);
    return "BLOCK---->  Address:"+address+"  Construction Year:"+yearStr+"  Total Apartments:"+totalStr+"  Occupied Apartments:"+occupiedStr;
}

