#pragma once
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
#include "Doctor.h"
class RepoDoctor
{
private:
	std::vector<Doctor> doctors;
public:
	RepoDoctor();
	std::vector<Doctor> getAllDoctors();
	Doctor parseDoctors(std::string line);
	~RepoDoctor() = default;
};

