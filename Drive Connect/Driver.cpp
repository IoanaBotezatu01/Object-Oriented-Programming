#include "Driver.h"

Driver::Driver()
{
	this->name = { "" };
	this->loation = { NULL };
	this->score = { 0 };

}

Driver::Driver(std::string name, Location location, int score)
{
	this->name = name;
	this->loation = location;
	this->score = score;
}

std::string Driver::getName() const
{
	return this->name;
}

Location Driver::getLocation() const
{
	return this->loation;
}

int Driver::getScore() const
{
	return this->score;
}

std::string Driver::toString()
{
	return this->name + " " + std::to_string(this->loation.latitude) + "," + std::to_string(this->loation.longitude) + " " + std::to_string(this->score);
}
