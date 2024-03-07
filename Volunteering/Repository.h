#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Departament.h"
#include "Volunteer.h"
class Repository
{
private:
	std::vector<Volunteer*> volunteers;
	std::vector<Department*>departments;
public:
	Repository();

	Volunteer* getVolunteerFromFile(std::string line);
	Department* getDepartmentFromFile(std::string line);
	std::vector<Department*> getDepartments();
	std::vector<Volunteer*>getVolunteers();
	void sortVolunteers();

	~Repository() = default;
};

