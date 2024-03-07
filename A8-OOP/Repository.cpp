#include "Repository.h"

int Repository::add_item_repo(Pet new_item)
{
	if (this->find_pet(new_item.get_name()) != -1)
		return 1;
	this->repo.push_back(new_item);
	return 0;
}

int Repository::remove_item_repo(std::string name)
{
	int position = this->find_pet(name);
	if (position == -1)
		return 1;
	this->repo.erase(this->repo.begin() + position);
	return 0;
}

void Repository::update_item_repo(Pet new_item)
{
	int found_pet_position = this->find_pet(new_item.get_name());
	if (found_pet_position != -1)
		this->set_repo_item(found_pet_position, new_item);
	else
		throw RepositoryException("The pet is not in the pet list, so there is nothing to be updated!\n");
}

int Repository::find_pet(std::string name)
{
	int length_pet_list = this->get_length(), i;
	for (i = 0; i < length_pet_list; i++)
		if (this->repo[i].get_name() == name)
			return i;
	return -1;
}

Pet Repository::get_repo_item(int position)
{
	return this->repo[position];
}

void Repository::set_item_adoption(int position, Pet adopted_pet)
{
	Pet new_pet(adopted_pet.get_breed(), adopted_pet.get_name(), adopted_pet.get_age(), adopted_pet.get_photograph(), true);
	this->set_repo_item(position, new_pet);
}

void Repository::set_repo_item(int position, Pet new_item)
{
	this->repo[position] = new_item;
}

int Repository::get_length()
{
	return this->repo.size();
}