#pragma once
#include "RepoDoctor.h"
#include"RepoPatient.h"
#include "Patient.h"
#include"Doctor.h"
#include<vector>
#include <string>

class Service
{
private:
	RepoDoctor repoDoctor;
	RepoPatient repoPatient;
public:
	Service(RepoDoctor& repodoctor, RepoPatient& repopatient);
	std::vector<Patient> getAllPatients();
	std::vector<Doctor> getAllDoctors();
	std::vector<Patient> getAssignedPatients(Doctor d);
	void addPatient(Patient p);
	void saveToFile(std::vector<Patient> p);
	void changeDiagnosisAndSpecialization(std::string name,std::string diagnosis,std::string specializzation);
	~Service() = default;
};

