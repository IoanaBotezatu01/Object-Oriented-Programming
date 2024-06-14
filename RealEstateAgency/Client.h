//
// Created by user on 09.05.2023.
//

#ifndef REALESTATEAGENCY_CLIENT_H
#define REALESTATEAGENCY_CLIENT_H
#include "string"
#include "Dwelling.h"

class Client {
private:
    std::string name;
    double income;
public:
    Client();
    Client(const std::string& ,const double);
    Client(Client& c);
    double totalIncome();
    std::string toString() const;
    virtual bool isInterested(Dwelling d);

};


#endif //REALESTATEAGENCY_CLIENT_H
