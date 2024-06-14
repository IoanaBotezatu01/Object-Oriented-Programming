//
// Created by user on 10.05.2023.
//

#include "House.h"


bool House::mustBeRestored()
{
    if(2023-constructionYear>100)
        return true;
    else
        return false;


}

House::House(std::string address, int constructionYear, bool isHistorical)
{
    this->address=address;
    this->constructionYear=constructionYear;
    this->isHistorical=isHistorical;
}

bool House::canBeDemolished() {
    if(isHistorical== false)
        return true;
    else
        return false;
}

std::string House::toString()
{
    std::string isHistStr;
    if(isHistorical==true)
        isHistStr="true";
    if(isHistorical== false)
        isHistStr="false";
    auto yearStr=std::to_string(constructionYear);
    return "HOUSE---->  Address:"+ this->address+"  Construction Year:"+yearStr+"  Historical:"+isHistStr;
}


