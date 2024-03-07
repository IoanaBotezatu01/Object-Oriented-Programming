#pragma once
#include <string>
class Doctor
{
	std::string name;
	std::string specialization;
public:
	Doctor();
	Doctor(std::string name, std::string specialization);
	std::string getName() const;
	std::string getSpecialization() const;
	std::string toString() const;
	~Doctor() = default;
};

