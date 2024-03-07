#include "Service.h"

Service::Service()
{
	std::ifstream file("list.txt");
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			List
				item = this->parseItem(line);
			this->list.push_back(item);
		}
	}
}

List Service::parseItem(std::string line)
{
	std::stringstream ss(line);
	std::string category, name, strQ;
	std::getline(ss, category, '|');
	std::getline(ss, name, '|');
	std::getline(ss, strQ, '|');
	auto quantity = stoi(strQ);

	return List(category, name, quantity);

}

std::vector<List> Service::getList()
{
	return this->list;
}

void Service::sortByCategoryAndName()
{
	std::sort(list.begin(), list.end(), [](const List& i1, const List& i2) {
		return i1.getName() < i2.getName(); 
		});
	std::sort(list.begin(), list.end(), [](const List& i1, const List& i2) {
		return i1.getCategory() < i2.getCategory();
		});
}
