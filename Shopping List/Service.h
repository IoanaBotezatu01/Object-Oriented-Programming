#pragma once
#include <vector>
#include <string>
#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
class Service
{
private:
	std::vector<List> list;
public:
	Service();
	List parseItem(std::string line);
	std::vector<List> getList();
	void sortByCategoryAndName();
	
	

	~Service() = default;
};

