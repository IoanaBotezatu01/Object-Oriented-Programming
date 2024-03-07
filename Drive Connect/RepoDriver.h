#pragma once
#include <string>
#include <vector>
#include "Driver.h"
#include<fstream>
#include <sstream>
#include <algorithm>
class RepoDriver
{private:
	std::vector<Driver> drivers;
public:
	RepoDriver();
	Driver parseDrivers(std::string line);
	std::vector<Driver> getAllDrivers();
	~RepoDriver() = default;

};

