#pragma once
#include "Departament.h"
#include "Volunteer.h"
#include "Repository.h"
#include <string>
#include <vector>
#include <algorithm>
#include "Departament.h"
#include "Volunteer.h"
class Service
{
private:
	Repository* repo;
public:
	Service(Repository& repo);
	std::vector<Department*> getDepartments();
	std::vector<Volunteer*>getVolunteers();
	~Service() = default;

};

