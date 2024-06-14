//
// Created by user on 09.05.2023.
//

#ifndef REALESTATEAGENCY_COMPANY_H
#define REALESTATEAGENCY_COMPANY_H
#include "string"
#include "Dwelling.h"
class Company {
private:
    double moneyFromInvestments;
public:
    double totalIncome();
    bool isInterested(Dwelling d);

};


#endif //REALESTATEAGENCY_COMPANY_H
