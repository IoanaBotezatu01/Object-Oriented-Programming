#include "Departament.h"

Department::Department() :name{ "" }, description{ "" }
{
}

Department::Department(const std::string& _name, const std::string& _description) :name{ _name }, description{ _description }
{
}

Department::Department(const Department& d)
{
	this->name = d.name;
	this->description = d.description;
}

std::string Department::getName() const
{
	return this->name;
}

std::string Department::getDescription() const
{
	return this->description;
}

std::string Department::toString()
{
	return this->name + " " + this->description;
}
