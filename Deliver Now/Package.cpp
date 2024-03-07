#include "Package.h"

Package::Package()
{
	this->recipient = { "" };
	this->address = { "" };
	this->location = { NULL };
	this->status = false;
}

Package::Package(std::string recipient, Address address, Location location, bool status)
{
	this->recipient = recipient;
	this->address = address;
	this->location = location;
	this->status = status;
}

std::string Package::getRecipient() const
{
	return this->recipient;
}

Address Package::getAddress() const
{
	return this->address;
}

Location Package::getLocation() const
{
	return this->location;
}

bool Package::getStatus()
{
	return this->status;
}

void Package::setStatus(bool status)
{
	this->status = status;
}

std::string Package::toString()
{
	auto strAddres = this->address.street+","+std::to_string(this->address.nr);
	auto strLocation = std::to_string(this->location.x)+","+std::to_string(this->location.y);
	return this->recipient + " " + strAddres + " " + strLocation + " " + std::to_string(this->status);
}

int Package::getX() const
{
	return this->location.x;
}

int Package::getY() const
{
	return this->location.y;
}
