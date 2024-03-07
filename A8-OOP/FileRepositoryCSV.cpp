#include "FileRepositoryCSV.h"

void FileRepositoryCSV::export_into_file(std::string filename)
{
	std::ofstream tofile(filename);
	std::vector<Pet> pet_list = this->get_repo_list();
	tofile << "Breed,Name,Age,Photograph,Adoption_status,\n";
	for (auto& current_pet : pet_list)
		tofile << current_pet.get_breed() << ',' << current_pet.get_name() << ',' << current_pet.get_age() << ',' << current_pet.get_photograph() << ',' << current_pet.get_adoption() << ",\n";
	tofile.close();
	this->displayPetList(filename);
}

void FileRepositoryCSV::displayPetList(std::string file_name)
{
	std::string path = "C:\\Users\\user\\Desktop\\a7-Botezatu-Ioana\\" + file_name;
	ShellExecuteA(NULL,
		"open",
		path.c_str(),
		NULL,
		NULL,
		SW_SHOWNORMAL
	);
}