#include "Pet.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Pet::Pet(string init_breed, string init_name, std::string init_age, string init_photograph, bool adopted)
{
	this->breed = init_breed;
	this->breed.assign(init_breed);

	this->name = init_name;
	this->name.assign(init_name);

	this->age = init_age;

	this->photograph = init_photograph;
	this->photograph.assign(init_photograph);

	this->adopted = adopted;
}

bool Pet::operator==(const Pet& other)
{
	return (this->age == other.age && this->breed == other.breed && this->name == other.name && this->photograph == other.photograph);
}

istream& operator>>(istream& input_type, Pet& pet) {
	string breed, name, age, photograph;

	cout << "Input the data of the pet ( <breed>,<name>,<age>,<phootograph> ): ";
	getline(input_type, breed, ',');
	getline(input_type, name, ',');
	getline(input_type, age, ',');
	getline(input_type, photograph, '\n');


	pet = Pet(breed, name, age, photograph, 0);
	return input_type;
}

ostream& operator<<(ostream& output_type, Pet& pet)
{
	output_type << pet.get_breed() << ',' << pet.get_name() << ',' << pet.get_age() << ',' << pet.get_photograph() << ',' << pet.get_adoption() << '\n';
	return output_type;
}

void Pet::set_breed(string new_breed)
{
	this->breed = new_breed;
}

void Pet::set_name(string new_name)
{
	this->name = new_name;
}

void Pet::set_photograph(string new_photograph)
{
	this->photograph = new_photograph;
}

void Pet::set_adoption(bool new_adoption_status)
{
	this->adopted = new_adoption_status;
}

std::string Pet::toString() const
{
	std::string str = "";
	str += "Breed: ";
	str += this->breed;
	str += "\nName: ";
	str += this->name;
	str += "\nAge: ";
	str += this->age;
	str += "\nPhotograph: ";
	str += this->photograph;
	str += "\n";
	return str;
}
