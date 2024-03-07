#include "RepoDriver.h"

RepoDriver::RepoDriver()
{
	std::ifstream filed("drivers.txt");
	if (filed.is_open())
	{
		std::string line;
		while (getline(filed, line))
		{
			Driver d = this->parseDrivers(line);
			this->drivers.push_back(d);
		}
	}
}

Driver RepoDriver::parseDrivers(std::string line)
{
	std::stringstream ss(line);
	std::string name, location, score;
	std::getline(ss, name, ' ');
	std::getline(ss, location, ' ');
	std::getline(ss, score, ' ');
	std::stringstream loc(location);
	std::string latitudestr, longitudestr;
	std::getline(loc, latitudestr, ',');
	std::getline(loc, longitudestr, ' ');
	int latitude = stoi(latitudestr);
	int longitude = stoi(longitudestr);
	int iscore = stoi(score);
	Location l{ latitude,longitude };
	Driver d=Driver( name,l,iscore );
	return d;
}

std::vector<Driver> RepoDriver::getAllDrivers()
{
	return this->drivers;
}
