#pragma once

typedef struct
{
	char* name;
	char* continent;
	double population;
}Country;

Country* createCountry(char* name, char* continent, double population);
void destroyCountry(Country* c);
char* getName(Country* c);
char* getContinent(Country* c);
double getPopulation(Country* c);
double setPopulation(Country* c, double newPopulation);



