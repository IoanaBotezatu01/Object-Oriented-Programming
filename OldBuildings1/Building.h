//
// Created by user on 10.05.2023.
//

#ifndef OLDBUILDINGS1_BUILDING_H
#define OLDBUILDINGS1_BUILDING_H
#include "string"

class Building {
protected:
    std::string address;
    int constructionYear;
public:
    Building()=default;
    virtual ~Building() {};
    virtual bool mustBeRestored()=0;
    virtual bool canBeDemolished()=0;
    virtual std::string toString()=0;
    int getYear();

};


#endif //OLDBUILDINGS1_BUILDING_H
