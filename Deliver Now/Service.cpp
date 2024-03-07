#include "Service.h"

Service::Service(RepoCourier& rc, RepoPackage& rp)
{
	this->repoCourier = rc;
	this->repoPackage = rp;
}

std::vector<Courier> Service::getCouriers()
{
	return this->repoCourier.getAllCouriers();
}

std::vector<Package> Service::getPackages()
{
	return this->repoPackage.getAllPackages();
}

void Service::addPackage(Package p)
{
	this->repoPackage.add(p);
}
