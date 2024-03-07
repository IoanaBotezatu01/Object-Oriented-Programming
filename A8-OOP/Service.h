#pragma once
#include "FileRepositoryCSV.h"
#include "FileRepositoryHTML.h"
#include <iostream>
#include <exception>
#include <fstream>
#include <memory>
#include <vector>

class Service
{
private:
	std::unique_ptr<FileRepository> pet_repo;

public:
	Service() = default;
	Service(std::unique_ptr<FileRepository> repo);

	void add_pet(std::string breed, std::string name, std::string age, std::string photograph);
	void remove_pet(std::string name);
	void update_pet(std::string breed, std::string name, std::string age, std::string photograph);

	int find_pet(std::string name);
	int find_unique_pet(std::string breed, std::string name, std::string age, std::string photograph);

	void adopt_pet(int pet_position, Pet adopted_pet);

	std::vector<Pet> get_pet_list();
	int get_pet_list_size();

	Pet get_pet(int position);
	void set_pet(int position, Pet pet);
	void setRepo(std::unique_ptr<FileRepository> repo);
	std::string get_filename();

	void export_into_file(std::string file_name, std::string extension);
};
