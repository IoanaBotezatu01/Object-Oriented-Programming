//
// Created by user on 09.05.2023.
//

#include "Client.h"
#include "string"

Client::Client():name{""},income{0}
{
}

Client::Client(Client &c)
{
    this->name=c.name;
    this->income=c.income;

}

Client::Client(const std::string &_name, const double _income):name{_name},income{_income}
{
}

double Client::totalIncome() {
    return 0;
}

std::string Client::toString() const
{
    auto strIncome= std::to_string(income);
    return this->name+" "+strIncome;
}

bool Client::isInterested(Dwelling d)
{
    return false;
}
