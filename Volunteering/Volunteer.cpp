#include "Volunteer.h"

Volunteer::Volunteer() :name{ "" }, email{ "" }, interests{ NULL }, department{ NULL }
{
}

Volunteer::Volunteer(const std::string& _name, const std::string _email, const std::vector<std::string>& _interests,Department* _department) :name{ _name
}, email{ _email }, interests{ _interests }, department{ _department }
{
}

Volunteer::Volunteer(const Volunteer& v)
{
	this->name = v.name;
	this->email = v.email;
	this->interests = v.interests;
	this->department = v.department;
}

std::string Volunteer::getName() const
{
	return this->name;
}

std::string Volunteer::getEmail() const
{
	return this->email;
}

std::vector<std::string> Volunteer::getInterests() const
{
	return this->interests;
}

Department* Volunteer::getDepartment() const
{
	return this->department;
}

std::string Volunteer::ToStringInterests() const
{
	std::string stringInterests;
	for (auto i : this->interests)
	{
		stringInterests += i + ",";
	}
	return stringInterests;
}

std::string Volunteer::ToString() const
{
	std::string Interests = this->ToStringInterests();
	return this->name + " " + this->email + " " + Interests + " " + this->department->toString();
}
