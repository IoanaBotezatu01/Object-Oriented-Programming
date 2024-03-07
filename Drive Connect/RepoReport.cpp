#include "RepoReport.h"

RepoReport::RepoReport()
{
	std::ifstream filer("reports.txt");

	if (filer.is_open())
	{
		std::string line;
		while (getline(filer, line))
		{
			Report r = this->parseReports(line);
			this->reports.push_back(r);
		}
	}
}

std::vector<Report> RepoReport::getAllReports()
{
	return this->reports;
}

Report RepoReport::parseReports(std::string line)
{
	std::stringstream ss(line);
	std::string description, reporter, location, status;
	std::getline(ss, description, ' ');
	std::getline(ss, reporter, ' ');
	std::getline(ss, location, ' ');
	std::getline(ss, status, ' ');
	std::stringstream loc(location);
	std::string latitudestr, longitudestr;
	std::getline(loc, latitudestr, ',');
	std::getline(loc, longitudestr, ' ');
	int latitude = stoi(latitudestr);
	int longitude = stoi(longitudestr);
	ExactLocation l{ latitude,longitude };
	bool bstatus;
	if (status == "false" || status == "0")
		bstatus = false;
	else
	{
		if (status == "true" || status == "1")
			bstatus = true;
	}
	Report r = Report(description, reporter, l, bstatus);
	return r;
}

void RepoReport::add(Report r)
{
	this->reports.push_back(r);
	this->saveToFile();
}

void RepoReport::saveToFile()
{
	std::ofstream filer("reports.txt");
	if(filer.is_open())
	for (auto i : this->reports)
	{
		filer << i.toString() << std::endl;

	}
	filer.close();
}
