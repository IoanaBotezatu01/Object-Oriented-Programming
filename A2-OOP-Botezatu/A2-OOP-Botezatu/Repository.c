#include "Repository.h"
#include <stdlib.h>
#include <string.h>

Repository* createRepository(int maxCapacity)
{
	Repository* repo = malloc(sizeof(Repository));
	if (repo == NULL)
		return repo;
	repo->size = 0;
	repo->countries = malloc(sizeof(Country) * maxCapacity);
	return repo;
}

void destroyRepository(Repository* repo)
{
	if (repo == NULL)
		return;
	for (int i = 0; i < repo->size; i++)
		destroyCountry(&repo->countries[i]); 
	free(repo->countries);
	free(repo);
}

int getSize(Repository* repo)
{
	if (repo == NULL)
		return 0;
	return repo->size;
}

int getCapacity(Repository* repo)
{
	if (repo == NULL)
		return 0;
	return repo->capacity;
}

void addCountry(Repository* repo, Country country)
{
	if (repo->size >= repo->capacity) 
		return 0;

	repo-> countries[repo->size] = country;
	repo->size++;
}

void deleteCountry(Repository* repository, char* name, char* continent) 
{
	for (int i = 0; i < repository->size; i++)
	{
		if (strcmp(name, repository->countries[i].name) == 0 &&
			strcmp(continent, repository->countries[i].continent) == 0) 
		{
			destroyCountry(&repository->countries[i]);
			repository->countries[i] = repository->countries[repository->size - 1];
			repository->size--;
			
		}
	}
}
void updateCountry(Repository* repository, char* name, char* continent, char* newName, char* newContinent,double newPopulation)
{
	for (int i = 0; i < repository->size; i++) {
		if (strcmp(name, repository->countries[i].name) == 0 && strcmp(continent, repository->countries[i].continent) == 0) 
		{
			Country *newCountry;
			newCountry = createCountry(newName, newContinent, newPopulation);

			destroyCountry(&repository->countries[i]);
			repository->countries[i] = *newCountry;
			
		}
	}
	
}

void migration(Repository* repo, char* country1, char* country2, double migr)
{
	int ok = 0, first_index, second_index;
	for (int i = 0; i < repo->size; i++) {
		if (strcmp(country1, repo->countries[i].name) == 0)
		{
			first_index = i;
		}
		if (strcmp(country2, repo->countries[i].name) == 0)
		{
			second_index = i;
			ok++;
		}
	}
		if (ok == 2)
	{
		if (repo->countries[first_index].population >= migr)
		{
			repo->countries[first_index].population = repo->countries[first_index].population - migr;
			repo->countries[second_index].population = repo->countries[second_index].population + migr;

		}

	}
		if (ok < 2)
			printf("One ore both countries are not in repo!\n");

}

Country* getAll(Repository* repo)
{
	return repo->countries;
}

Country* searchByName(Repository* repository, char* substring, int* nrelem)
{
	Country* countriesFound;
	countriesFound = countriesContainingSubString(repository, substring, nrelem);
	return countriesFound;
}

Country* countriesContainingSubString(Repository* repository, char* substring, int* nrelem)
{
	int size = repository->size;
	Country* countries = repository->countries;
	Country* countriesFound = malloc(sizeof(Country) * size);
	for (int i = 0; i < size; i++) {
		if (strstr(countries[i].name, substring) != NULL)
		{
			countriesFound[(*nrelem)] = countries[i];
			(*nrelem)++;
		}
	}
	return countriesFound;
}



