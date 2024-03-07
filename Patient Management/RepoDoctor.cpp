#include "RepoDoctor.h"

RepoDoctor::RepoDoctor()
{
	std::ifstream filed("doctors.txt");
	if (filed.is_open())
	{
		std::string line;
		while (std::getline(filed, line))
		{
			Doctor d = this->parseDoctors(line);
			this->doctors.push_back(d);
		}
	}
}

std::vector<Doctor> RepoDoctor::getAllDoctors()
{
	return this->doctors;
}

Doctor RepoDoctor::parseDoctors(std::string line)
{
	std::stringstream ss(line);
	std::string name, specialization;
	std::getline(ss, name, ' ');
	std::getline(ss, specialization, ' ');
	Doctor d(name, specialization);
	return d;
}
