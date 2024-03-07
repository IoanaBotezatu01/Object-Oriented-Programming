#pragma once
#include "FileRepository.h"

class FileRepositoryCSV:
	public FileRepository
{
public:
	FileRepositoryCSV(const std::string& filename) : FileRepository{ filename } {};
	void export_into_file(std::string file) override;
	void displayPetList(std::string file_name) override;
};
