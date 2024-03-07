#include "Patient.h"
#include "RepoPatient.h"

Patient::Patient()
{
	this->name = "";
	this->diagnosis = "";
	this->specialization = "";
	this->doctor = "";
	this->date = "";
}

Patient::Patient(std::string name, std::string diagnosis, std::string specialization, std::string doctor, std::string date)
{
	this->name = name;
	this->diagnosis = diagnosis;
	this->specialization = specialization;
	this->doctor = doctor;
	this->date = date;
}

std::string Patient::getName() const
{
	return this->name;
}

std::string Patient::getDiagnosis() const
{
	return this->diagnosis;
}

std::string Patient::getSpecialization() const
{
	return this->specialization;
	
}

std::string Patient::getDoctor() const
{
	return this->doctor;
}

std::string Patient::getDate() const
{
	return this->date;
}

void Patient::setDiagnosis(std::string diagnosis)
{
	this->diagnosis = diagnosis;

}

void Patient::setSpecialization(std::string specialization)
{
	this->specialization = specialization;

}

std::string Patient::toString()
{
	return this->name + " " + this->diagnosis + " " + this->specialization + " " + this->doctor + " " + this->date;
}
