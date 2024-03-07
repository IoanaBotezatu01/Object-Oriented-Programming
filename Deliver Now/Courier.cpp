#include "Courier.h"

Courier::Courier()
{
	this->name = "";
	this->streets = { NULL };
	this->zone = { NULL };

}

Courier::Courier(std::string name, std::vector<std::string> s, Zone zone)
{
	this->name = name;
	this->streets = s;
	this->zone = zone;
}

std::string Courier::getName() const
{
	return this->name;
}

std::vector<std::string> Courier::getStreets() const
{
	return  this->streets;
}

Zone Courier::getZone() const
{
	return this->zone;
}
