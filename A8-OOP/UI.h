#pragma once
#include "Service.h"
#include <vector>
#include "Pet.h"
#include <iostream>
#include <string>

class UI
{
protected:
	Service service;
	std::string user_file_option;
	FileRepository* pet_repo;

public:
	UI(std::string file, std::string user_file_option);

	void start();
	
};
