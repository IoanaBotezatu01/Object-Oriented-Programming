#include "Report.h"

Report::Report()
{
	this->description = { "" };
	this->reporter = { "" };
	this->location = { NULL };
	this->status = { 0 };
}

Report::Report(std::string description, std::string reporter, ExactLocation location, bool status)
{
	this->description = description;
	this->reporter = reporter;
	this->location = location;
	this->status = status;
}

std::string Report::getDescription() const
{
	return this->description;
}

std::string Report::getReporter() const
{
	return this->reporter;
}

ExactLocation Report::getlocation() const
{
	return this->location;
}

bool Report::getStatus() const
{
	return this->status;
}

std::string Report::toString()
{
	return this->description + " " + this->reporter + " " + std::to_string(this->location.latitude) + "," + std::to_string(this->location.longitude) + " " + std::to_string(this->status);
}
