#pragma once
#include <string>

class Patient
{
private:
	std::string name;
	std::string diagnosis;
	std::string specialization;
	std::string doctor;
	std::string date;
public:
	Patient();
	Patient(std::string name, std::string diagnosis, std::string specialization, std::string doctor, std::string date);
	std::string getName() const;
	std::string getDiagnosis() const;
	std::string getSpecialization()  const;
	std::string getDoctor() const;
	std::string getDate() const;
	void setDiagnosis(std::string diagnosis);
	void setSpecialization(std::string specialization);
	std::string toString();
	~Patient() = default;
};

