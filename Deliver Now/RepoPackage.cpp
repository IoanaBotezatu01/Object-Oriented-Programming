#include "RepoPackage.h"

RepoPackage::RepoPackage()
{
	std::ifstream filepackage("packages.txt");
	if (filepackage.is_open())
	{
		std::string line;
		while (getline(filepackage, line))
		{

		Package p = this->parsePackage(line);
		this->packages.push_back(p);
		}
	}
}

Package RepoPackage::parsePackage(std::string line)
{
	std::stringstream ss(line);
	std::string name, address, location, strstatus;
	std::getline(ss, name, ' ');
	std::getline(ss, address, ' ');
	std::getline(ss, location, ' ');
	std::getline(ss, strstatus, ' ');
	std::stringstream ad(address);
	std::string street, number;
	std::getline(ad, street, ',');
	std::getline(ad, number, ' ');
	int nr = stoi(number);
	Address addressf;
	addressf.street = street;
	addressf.nr = nr;
	std::stringstream loc(location);
	std::string strx, stry;
	Location l;
	std::getline(loc, strx, ',');
	int x = stoi(strx);
	l.x = x;
	std::getline(loc, stry, ',');
	int y = stoi(stry);
	l.y = y;
	bool status;
	if (strstatus == "0")
		status = false;
	else
		status = true;

	Package p = Package(name, addressf, l, status);
	return p;
}

std::vector<Package> RepoPackage::getAllPackages()
{
	return this->packages;
}

void RepoPackage::add(Package p)
{
	this->packages.push_back(p);
}

void RepoPackage::savetofile()
{
	std::ofstream filep("packages.txt");
	if (filep.is_open())
	{
		filep.clear();
	for (auto i : this->packages)
	{
		filep << i.toString() << "\n";
	}
	}
	
}
