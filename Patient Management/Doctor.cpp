#include "Doctor.h"

Doctor::Doctor()
{
	this->name = "";
	this->specialization = "";
}

Doctor::Doctor(std::string name, std::string specialization)
{
	this->name = name;
	this->specialization = specialization;
}

std::string Doctor::getName() const
{
	return this->name;
}

std::string Doctor::getSpecialization() const
{
	return this->specialization;
}

std::string Doctor::toString() const
{
	return this->name + " " + this->specialization;
}
