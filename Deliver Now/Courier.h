#pragma once
#include <string>
#include <vector>
struct Zone
{
	int x;
	int y;
	int r;
};
class Courier
{
private:
	std::string name;
	std::vector<std::string> streets;
	Zone zone;
public:
	Courier();
	Courier(std::string name, std::vector<std::string> steerts, Zone zone);
	std::string getName() const;
	std::vector<std::string> getStreets() const;
	Zone getZone() const;

};

