#include "FileRepositoryHTML.h"

void FileRepositoryHTML::export_into_file(std::string filename)
{
	std::ofstream tofile(filename);
	std::vector<Pet> pet_list = this->get_repo_list();
	tofile << "<!DOCTYPE html><html><head></head><body>";
	tofile << "<table><thead><tr><th>Breed</th><th>Name</th><th>Age</th><th>Photograph</th><th>Adoption status</th></tr></thead><tbody>";
	for (auto& current_pet : pet_list)
		tofile << "<tr><td>" << current_pet.get_breed() << "</td><td>" << current_pet.get_name() << "</td><td>" << current_pet.get_age() << "</td><td>" << current_pet.get_photograph() << "</td><td>" << current_pet.get_adoption() << "</td></tr>";
	tofile << "</tbody></table></body></html>";
	tofile.close();
	this->displayPetList(filename);
}

void FileRepositoryHTML::displayPetList(std::string file_name)
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
