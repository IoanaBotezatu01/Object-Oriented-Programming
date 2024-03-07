#pragma once
#include <vector>
#include<string>
#include"RepoDriver.h"
#include"RepoReport.h"
#include "Report.h"
#include "Driver.h"
class Service
{
private:
	RepoDriver repoDriver;
	RepoReport repoReport;
public:
	Service(RepoDriver& rd, RepoReport& rr);
	std::vector<Driver> getAllDrivers();
	std::vector<Report> getAllReports();
	std::vector<Report>getAssignedReports(Driver d);
	void addReport(Report r);
	std::vector<Report> getValid();
	~Service() = default;
};

