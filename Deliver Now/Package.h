#pragma once
#include <string>
#include <vector>
struct Location
{
	int x;
	int y;
};
struct Address
{
	std::string street;
	int nr;
};
class Package
{
private:
	std::string recipient;
	Address address;
	Location location;
	bool status;
public:
	Package();
	Package(std::string recipient, Address address, Location location, bool status);
	std::string getRecipient() const;
	Address getAddress() const;
	Location getLocation() const;
	bool getStatus();
	void setStatus(bool status);
	std::string toString();
	int getX()const;
	int getY()const;
	~Package() = default;

};

