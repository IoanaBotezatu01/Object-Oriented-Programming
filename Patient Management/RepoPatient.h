#pragma once
#include <sstream>
#include<fstream>
#include <vector>
#include <string>
#include "Patient.h"
#include<algorithm>
class RepoPatient
{
private:
	std::vector<Patient> patients;
public:
	RepoPatient();
	std::vector<Patient> getAllPatients();
	Patient parsePatients(std::string line);
	//void sortByDate();
	//bool compareByDate(Patient p1, Patient p2);
	void add(Patient p);
	void saveToFile(std::vector<Patient> p);
	void changeDiagnosisAndSpecialization(std::string name, std::string diagnosis, std::string specialization);
	~RepoPatient() = default;
};

