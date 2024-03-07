#include "Service.h"

Service::Service(RepoDriver& rd, RepoReport& rr)
{
	this->repoDriver = rd;
	this->repoReport = rr;
}

std::vector<Driver> Service::getAllDrivers()
{
	return this->repoDriver.getAllDrivers();

}

std::vector<Report> Service::getAllReports()
{
	return this->repoReport.getAllReports();
}

std::vector<Report> Service::getAssignedReports(Driver d)
{
	std::vector<Report> assignedReports;
	for (auto r : this->getAllReports())
	{
		auto dist = sqrt((r.getlocation().latitude - d.getLocation().latitude) * (r.getlocation().latitude - d.getLocation().latitude) + (r.getlocation().longitude - d.getLocation().longitude) * (r.getlocation().longitude - d.getLocation().longitude));
		if (dist <= 10)
			assignedReports.push_back(r);

	}
	return assignedReports;
}

void Service::addReport(Report r)
{
	this->repoReport.add(r);
}

std::vector<Report> Service::getValid()
{
	std::vector<Report> valids;
	for (auto r : this->getAllReports())
		if (r.getStatus())
			valids.push_back(r);
	return valids;
}
