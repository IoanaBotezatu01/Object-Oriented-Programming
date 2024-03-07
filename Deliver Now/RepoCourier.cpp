#include "RepoCourier.h"

RepoCourier::RepoCourier()
{
	std::ifstream filecourier("couriers.txt");
	if (filecourier.is_open())
	{
		std::string line;
		while (getline(filecourier, line))
		{
			Courier c = this->parseCourier(line);
			couriers.push_back(c);
		}
	}
}

Courier RepoCourier::parseCourier(std::string line)
{
	std::stringstream ss(line);
	std::string name, streets, zone;

	std::getline(ss, name, ' ');
	std::getline(ss, streets, ' ');
	std::getline(ss, zone, ' ');

	std::vector<std::string> streetsv;
	std::string s;
	std::stringstream ss1(streets);
	while (getline(ss1, s, ','))
	{
		streetsv.push_back(s);
	}
	/*std::getline(ss1, s, ' ');
	streetsv.push_back(s);*/
	std::stringstream ss2(zone);
	std::string strx, stry, strradius;
	std::getline(ss2, strx, ',');
	int x = stoi(strx);
	std::getline(ss2, stry, ',');
	int y = stoi(stry);
	std::getline(ss2, strradius, ' ');
	int radius = stoi(strradius);
	Zone z;
	z.x = x;
	z.y = y;
	z.r = radius;
	Courier c = Courier(name, streetsv, z);
	return c;


}

std::vector<Courier> RepoCourier::getAllCouriers()
{
	return this->couriers;
}
