#pragma once
#include <string>
#include <vector>
#include "Departament.h"
class Volunteer
{
private:
	std::string name;
	std::string email;
	std::vector<std::string> interests;
	Department* department;
public:
	Volunteer();
	Volunteer(const std::string& name, const std::string email, const std::vector<std::string>& interests, Department* department);
	Volunteer(const Volunteer& v);
	std::string getName() const;
	std::string getEmail() const;
	std::vector<std::string> getInterests() const;
	Department* getDepartment() const;
	std::string ToStringInterests() const;
	std::string ToString() const;
	~Volunteer()=default;
};

