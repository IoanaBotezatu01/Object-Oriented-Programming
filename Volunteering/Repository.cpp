#include "Repository.h"

Repository::Repository()
{
	std::ifstream filed("departments.txt");
	if (filed.is_open())
	{
		std::string line;
		while (getline(filed, line))
		{
			Department* d = this->getDepartmentFromFile(line);
			this->departments.push_back(d);
		}
	}

	std::ifstream filev("volunteers.txt");
	if (filev.is_open())
	{
		std::string line;
		while (getline(filev, line))
		{
			Volunteer* v = this->getVolunteerFromFile(line);
			this->volunteers.push_back(v);
		}
	}
	this->sortVolunteers();
	

}

Volunteer* Repository::getVolunteerFromFile(std::string line)
{
	std::stringstream ss(line);
	std::string name, email , interests,department;
	std::getline(ss, name, ' ');
	std::getline(ss, email, ' ');
	std::getline(ss, interests, ' ');
	std::getline(ss, department, ' ');

	std::stringstream ss1(interests);
	
	std::vector<std::string> inter;
	std::string temp;
	while (getline(ss1, temp, ',')) {
		inter.push_back(temp);
	}
	getline(ss1, temp);
	inter.push_back(temp);
	Department* dep;
	for (auto i : this->departments)
	{
		if (i->getName() == department)
		{
			dep = new Department(i->getName(), i->getDescription());
			break;
		}
	}
	Volunteer* vol = new Volunteer(name, email, inter, dep);
	return vol;
}

Department* Repository::getDepartmentFromFile(std::string line)
{
	std::stringstream ss(line);
	std::string name, description;
	std::getline(ss, name, ' ');
	std::getline(ss, description, ' ');
	if (name.empty())
		return nullptr; // Return nullptr if the name is empty

	Department* dep = new Department(name, description);
	return dep;
}


std::vector<Department*> Repository::getDepartments()
{
	return this->departments;
}

std::vector<Volunteer*> Repository::getVolunteers()
{
	return this->volunteers;
}

void Repository::sortVolunteers()

{
	auto vol = this->volunteers;
	std::sort(vol.begin(), vol.end(), [](const Volunteer* v1, const Volunteer* v2) {
		return v1->getName() < v2->getName();
		});
}
