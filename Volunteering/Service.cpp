#include "Service.h"

Service::Service(Repository& _repo): repo{&_repo}
{
}

std::vector<Department*> Service::getDepartments()
{
	return this->repo->getDepartments();
}

std::vector<Volunteer*> Service::getVolunteers()
{
	return this->repo->getVolunteers();
}
