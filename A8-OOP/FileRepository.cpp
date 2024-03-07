#include "FileRepository.h"

FileRepository::FileRepository(std::string file)
{
	this->file = file;
	this->read_from_file();
}

int FileRepository::add_item_repo(Pet new_item)
{
	Repository::add_item_repo(new_item);
	std::ofstream fout(this->file, std::ios_base::app);
	fout << new_item;
	fout.close();
	return 0;
}

int FileRepository::remove_item_repo(std::string name)
{
	Repository::remove_item_repo(name);
	this->write_to_file();
	return 0;
}

void FileRepository::update_item_repo(Pet new_item)
{
	Repository::update_item_repo(new_item);
	this->write_to_file();
}

int FileRepository::find_pet(std::string name)
{
	return Repository::find_pet(name);
}

Pet FileRepository::get_repo_item(int position)
{
	return Repository::get_repo_item(position);
}

void FileRepository::set_item_adoption(int position, Pet adopted_pet)
{
	Repository::set_item_adoption(position, adopted_pet);
	this->write_to_file();
}

void FileRepository::set_repo_item(int position, Pet new_item)
{
	Repository::set_repo_item(position, new_item);
	this->write_to_file();
}

int FileRepository::get_length()
{
	return Repository::get_length();
}

std::vector<std::string> FileRepository::split_for_read(std::string text)
{
	std::istringstream stream(text);
	std::string current_word;
	std::vector<std::string> vector_words;

	while (getline(stream, current_word, ',')) 
	{
		vector_words.push_back(current_word);
	}
	return vector_words;
}

void FileRepository::read_from_file()
{
	std::ifstream fin(this->file);
	std::string line;
	std::vector<std::string> current_line_words;
	while (std::getline(fin, line, '\n'))
	{
		current_line_words = this->split_for_read(line);
		Pet new_pet(current_line_words[0], current_line_words[1], current_line_words[2], current_line_words[3], (bool)stoi(current_line_words[4]));
		Repository::add_item_repo(new_pet);
	}
	fin.close();
}

void FileRepository::write_to_file()
{
	std::ofstream fout(this->file);
	for (int i = 0; i < this->get_length(); i++)
	{
		//fout << this->get_repo_item(i);
	}
	fout.close();
}

std::string FileRepository::get_filename() const
{
	return this->file;
}
