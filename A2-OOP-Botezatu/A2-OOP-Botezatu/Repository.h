#pragma once
#include "Country.h"

typedef struct 
{
	Country* countries;
	int capacity;
	int size;
}Repository;

Repository* createRepository(int maxCapacity);
void destroyRepository(Repository* repo);
int getSize(Repository*);
int getCapacity(Repository*);

void deleteCountry(Repository*, char* name, char* country);
void updateCountry(Repository*, char*name, char* continent, char* newName, char* newContinent, double NewPopulation);
void migration(Repository*, char* country1, char* country2, double migr);


int getSize(Repository* repo);
void addCountry(Repository* repo,Country country);

Country* getAll(Repository* repo);

Country* searchByName(Repository*, char*, int*);

Country* countriesContainingSubString(Repository*, char*, int*);


