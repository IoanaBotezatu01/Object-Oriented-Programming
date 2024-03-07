#include "Country.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Country* createCountry(char* name, char* continent, double population)
{
	Country* c = malloc(sizeof(Country));
	
	if (c == NULL)
		return NULL;
	
	
	c->name = (char*)malloc(sizeof(char) *(strlen(name) + 1));
	c->continent =(char*) malloc(sizeof(char) * (strlen(continent) + 1));
	if (c->name != NULL)
		memcpy(c->name, name, strlen(name) + 1);
	if (c->continent != NULL)
		memcpy(c->continent, continent, strlen(continent) + 1);

	c->population = population;

	return c;
}

void destroyCountry(Country* c)
{
	if (c == NULL)
		return;
	free(c->name);
	free(c->continent);

}

char* getName(Country* c)
{
	if (c == NULL)
		return;
	return c->name;
}

char* getContinent(Country* c)
{
	if (c == NULL)
		return;
	return c->continent;
}

double getPopulation(Country* c)
{
	if (c == NULL)
		return ;
	return c->population;
}

double setPopulation(Country* c,double newPopulation)
{
	c->population = c->population + newPopulation;

}
