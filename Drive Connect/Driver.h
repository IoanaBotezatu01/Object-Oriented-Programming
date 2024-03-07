#pragma once
#include <string>
#include <vector>
struct Location {
	int latitude;
	int longitude;
};
class Driver
{
private:
	std::string name;
	Location loation;
	int score;
public:
	Driver();
	Driver(std::string name, Location location, int score);
	std::string getName()const;
	Location getLocation()const;
	int getScore()const;
	std::string toString();
	~Driver()=default;
};


