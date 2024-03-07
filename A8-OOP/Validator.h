#pragma once
#include "Exceptions.h"
#include <string>

class Validator
{
public:
	static int is_number(std::string number);
	static int valid_age(std::string age);
	static void valid_name(std::string name);
	static void valid_breed(std::string breed);
	static void validateDog(std::string breed, std::string name, std::string age, std::string photograph);
};

