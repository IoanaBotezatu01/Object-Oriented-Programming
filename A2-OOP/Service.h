#pragma once
#include "Repository.h"
#include "Country.h"


typedef struct {
    Repository* repo;
}Service;

Service* createService(Repository* r);
void destroyService(Service* s);

void addCountryFromService(Service* s, char* name, char* continent, double population);
void deleteCountryFromService(Service* s, char* name);
void updateCountryFromService(Service* s, char* name, char* continent, double population);
