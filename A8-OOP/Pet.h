#pragma once
#include <string>

class Pet
{
private:
	std::string breed;
	std::string name;
	std::string age;
	std::string photograph;
	bool adopted;

public:
	Pet() = default;
	Pet(std::string breed, std::string name, std::string age, std::string photograph, bool adopted);

	bool operator==(const Pet& other);

	friend std::istream& operator>>(std::istream& input_type, Pet& pet);
	friend std::ostream& operator<<(std::ostream& output_type, Pet& pet);

	std::string get_breed() { return this->breed; }

	std::string get_name() { return this->name; }

	std::string get_age() { return this->age; }

	std::string get_photograph() { return this->photograph; }

	bool get_adoption() { return this->adopted; }

	void set_breed(std::string new_breed);

	void set_name(std::string new_name);

	void set_age(std::string new_age) { this->age = new_age; }

	void set_photograph(std::string new_photograph);

	void set_adoption(bool new_adoption_status);
	std::string toString() const;
};
