#pragma once
#include <string>
class Department	
{
private:
	std::string name;
	std::string description;
public:
	Department();
	Department(const std::string& name, const std::string& description);
	Department(const Department& d);
	std::string getName() const;
	std::string getDescription() const;
	std::string toString();
	~Department() = default;
};

