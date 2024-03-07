#pragma once
#include "Package.h"
#include "Courier.h"
#include "RepoCourier.h"
#include "RepoPackage.h"
#include <vector>
#include <string>

class Service
{
private:
	RepoCourier repoCourier;
	RepoPackage repoPackage;
public:
	Service(RepoCourier& rc, RepoPackage& rp);
	std::vector<Courier> getCouriers();
	std::vector<Package> getPackages();
	void addPackage(Package p);
	~Service() = default;
};

