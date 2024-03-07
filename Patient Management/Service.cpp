#include "Service.h"

Service::Service(RepoDoctor& repodoctor, RepoPatient& repopatient)
{
	this->repoDoctor = repodoctor;
	this->repoPatient = repopatient;
}

std::vector<Patient> Service::getAllPatients()
{
	return this->repoPatient.getAllPatients();
}

std::vector<Doctor> Service::getAllDoctors()
{
	return this->repoDoctor.getAllDoctors();
}

std::vector<Patient> Service::getAssignedPatients(Doctor d)
{
	std::vector<Patient> assignedPatients;
	for (auto i : this->getAllPatients())
	{
		if (i.getSpecialization() == d.getSpecialization()||i.getDiagnosis()=="undiagnosed")
			assignedPatients.push_back(i);
	}
	return assignedPatients;
}

void Service::addPatient(Patient p)
{
	this->repoPatient.add(p);
}

void Service::saveToFile(std::vector<Patient> p)
{
	this->repoPatient.saveToFile(p);
}

void Service::changeDiagnosisAndSpecialization(std::string name, std::string diagnosis, std::string specializzation)
{
	this->repoPatient.changeDiagnosisAndSpecialization(name, diagnosis, specializzation);
}
