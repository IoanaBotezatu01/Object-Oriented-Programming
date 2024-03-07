#pragma once
#include "Repository.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <shellapi.h>

class FileRepository: public Repository
{
private:
	std::string file = "file.txt";

public:
	FileRepository() = default;
	FileRepository(std::string file);

	virtual int add_item_repo(Pet new_item) override;
	virtual int remove_item_repo(std::string name) override;
	void update_item_repo(Pet new_item) override;
	int find_pet(std::string name) override;
	 
	Pet get_repo_item(int position);
	void set_item_adoption(int position, Pet adopted_pet);
	void set_repo_item(int position, Pet new_item);
	int get_length();

	std::vector<std::string> split_for_read(std::string text);

	std::vector<Pet> get_repo()override{ return Repository::get_repo(); };

	void read_from_file();
	void write_to_file();
	std::string get_filename() const;

	virtual void export_into_file(std::string file) override {};
	virtual void displayPetList(std::string file_name) {};
};

