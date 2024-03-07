#pragma once
#include "Pet.h"
#include <vector>
#include "Exceptions.h"

class Repository
{
private:
	std::vector<Pet> repo;

public:
	Repository() = default;

	virtual int add_item_repo(Pet new_item);
	virtual int remove_item_repo(std::string name);
	virtual void update_item_repo(Pet new_item);
	virtual int find_pet(std::string name);

	Pet get_repo_item(int position);
	virtual void set_item_adoption(int position, Pet adopted_pet);
	virtual void set_repo_item(int position, Pet new_item);
	int get_length();

	std::vector<Pet> get_repo_list() { return this->repo; };

	virtual std::vector<Pet> get_repo() { return this->repo; };

	virtual void export_into_file(std::string file_name) = 0;

};
