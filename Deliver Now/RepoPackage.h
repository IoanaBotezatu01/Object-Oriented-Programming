#pragma once
#include "Package.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
class RepoPackage
{
private:
	std::vector<Package> packages;
public:
	RepoPackage();
	Package parsePackage(std::string line);
	std::vector<Package> getAllPackages();
	void add(Package p);
	~RepoPackage() = default;
	void savetofile();
};

