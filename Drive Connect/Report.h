#pragma once
#include <string>
#include <vector>
struct ExactLocation {
	int latitude;
	int longitude;
};
class Report
{
private:
	std::string description;
	std::string reporter;
	ExactLocation location;
	bool status;
public:
	Report();
	Report(std::string description, std::string reporter, ExactLocation loation, bool status);
	std::string getDescription() const;
	std::string getReporter()const;
	ExactLocation getlocation()const;
	bool getStatus()const;
	std::string toString();
	~Report()=default;
};

