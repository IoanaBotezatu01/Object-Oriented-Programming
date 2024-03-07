#include "RepoPatient.h"

RepoPatient::RepoPatient()
{
	std::ifstream filep("patientstxt.txt");
	if(filep.is_open())
	{
		std::string line;
		while (std::getline(filep, line))
		{
			Patient p = this->parsePatients(line);
			this->patients.push_back(p);
		}
	}
	//this->sortByDate();
}

std::vector<Patient> RepoPatient::getAllPatients()
{
	return this->patients;
}

Patient RepoPatient::parsePatients(std::string line)
{
	std::stringstream ss(line);
	std::string name, diagnosis, specialization, doctor, date;
	std::getline(ss, name, ' ');
	std::getline(ss, diagnosis, ' ');
	if (diagnosis == "undiagnosed")
	{
		Patient p(name, diagnosis,"", "", "");
		return p;
	}
	else
	{
		std::getline(ss, specialization, ' ');
		std::getline(ss, doctor, ' ');
		std::getline(ss, date, ' ');
		Patient p(name, diagnosis, specialization, doctor, date);
		return p;
	}
}
void RepoPatient::add(Patient p)
{
	this->patients.push_back(p);
	this->saveToFile(this->patients);
}

void RepoPatient::saveToFile(std::vector<Patient> p)
{
	std::ofstream filep("patientstxt.txt");
	if (filep.is_open())
	{
		filep.clear();
		for (auto i : p)
			filep << i.toString() << std::endl;
	}
	filep.close();
}

void RepoPatient::changeDiagnosisAndSpecialization(std::string name, std::string diagnosis, std::string specialization)
{
	auto p = this->patients;
	int nr = 0;
	for (auto i : p)
	{
		if (i.getName() == name)
		{
			i.setDiagnosis(diagnosis);
			i.setSpecialization(specialization);
			this->patients[nr] = i;
			
		}
		nr++;
	}
	this->saveToFile(this->patients);
}

//
//void RepoPatient::sortByDate()
//{
//	std::sort(this->patients.begin(), this->patients.end(),compareByDate);
//}
//
//bool RepoPatient::compareByDate(Patient p1, Patient p2)
//{
//	std::istringstream iss1(p1.getDate());
//	std::istringstream iss2(p2.getDate());
//
//	int day1, month1, year1, day2, month2, year2;
//	char delimiter;
//
//	iss1 >> day1 >> delimiter >> month1 >> delimiter >> year1;
//	iss2 >> day2 >> delimiter >> month2 >> delimiter >> year2;
//
//	// Comparing the dates in descending order (from newest to oldest)
//	if (year1 != year2) {
//		return year1 > year2;
//	}
//	else if (month1 != month2) {
//		return month1 > month2;
//	}
//	else {
//		return day1 > day2;
//	}
//}
