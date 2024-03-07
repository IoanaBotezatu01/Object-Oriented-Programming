#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Report.h"
class RepoReport
{
private:
	std::vector<Report> reports;
public:
	RepoReport();
	std::vector<Report> getAllReports();
	Report parseReports(std::string line);
	void add(Report r);
	void saveToFile();
	~RepoReport() = default;
};

