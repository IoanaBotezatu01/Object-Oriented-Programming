#pragma once
#include<vector>
#include<string>
#include "Courier.h"
#include <fstream>
#include <sstream>
class RepoCourier
{
private:
	std::vector<Courier> couriers;
public:
	RepoCourier();
	Courier parseCourier(std::string line);
	std::vector<Courier> getAllCouriers();
	~RepoCourier() = default;
};

