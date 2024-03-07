#include "Country.h"
#include <stdio.h>
#include <crtdbg.h>
#include "main.h"
#include "Ui.h"
#include "Repository.h"

int main()
{
	int ok = 1;
	Repository* repo;
	repo = createRepository(120);
	Country* c1,* c2,* c3,* c4,* c5, *c6,* c7, *c8, *c9, *c10;

	c1 = createCountry("Romania", "Europe", 19.1);
	c2 = createCountry("Spain", "Europe", 47.2);
	c3 = createCountry("China", "Asia", 1412.5);
	c4 = createCountry("Bulgary", "Europe", 6.8);
	c5 = createCountry("Hungary", "Europe", 9.7);
	c6 = createCountry("Cuba", "America", 11.2);
	c7 = createCountry("Madagascar", "Africa", 28.9);
	c8 = createCountry("Russia", "Asia", 143.4);
	c9 = createCountry("Ukraine", "Europe", 43.7);
	c10 = createCountry("Maroc", "Africa", 37.08);
	printf("%s ", c7->name);
	printf("%s ", c7->continent);
	printf("%g\n", c7->population);

	addCountry(&repo, *c1);
	addCountry(&repo, *c2);
	addCountry(&repo, *c3);
	addCountry(&repo, *c4);
	addCountry(&repo, *c5);
	addCountry(&repo, *c6);
	addCountry(&repo, *c7);
	addCountry(&repo, *c8);
	addCountry(&repo, *c9);
	addCountry(&repo, *c10);

	
	double pop;
	int option;
	while (ok==1)
	{
		print_menu();
		scanf("%d", &option);
		if (option == 0)
			ok = 2;
	if (option == 1)
	{
		char *name, *continent;
		name = (char*)malloc(sizeof(char) * 100);
		continent = (char*)malloc(sizeof(char) * 100);
		printf("Name:");
		scanf("%s", &name);
		printf("Continent:");
		scanf("%s", &continent);
0;		printf("Population(in milions):");	
		scanf("%g", &pop);
		
		Country *c;
		c = createCountry(  name,continent, pop);
		
		addCountry(&repo, *c);
	
		destroyCountry(&c);

	}
	else if (option == 2)
	{
		char* name, * continent;
		name = (char*)malloc(sizeof(char) * 100);
		continent = (char*)malloc(sizeof(char) * 100);
		printf("Name:");
		scanf("%s", &name);
		printf("Continent:");
		scanf("%s", &continent);
		deleteCountry(&repo, name, continent);
		
	}
	else if (option == 3)
	{
		char* name, * continent, * new_name, * new_continent;
		double population;
		name = (char*)malloc(sizeof(char) * 100);
		continent = (char*)malloc(sizeof(char) * 100);
		new_name = (char*)malloc(sizeof(char) * 100);
		new_continent = (char*)malloc(sizeof(char) * 100);
		printf("Name:");
		scanf("%s", &name);
		printf("Continent:");
		scanf("%s", &continent);
		printf("New name:");
		scanf("%s", &new_name);
		printf("New continent:");
		scanf("%s", &new_continent);
		printf("New population:");
		scanf("%d", &population);
		updateCountry(&repo, name, continent, new_name, new_continent, population);
		

	}
	else if (option == 4)
	{
		char* country1, * country2;
		int pop;
		country1 = (char*)malloc(sizeof(char) * 100);
		country2 = (char*)malloc(sizeof(char) * 100);
		printf("Choose the first country:");
		scanf("%s", &country1);
		printf("Choose the second country:");
		scanf("%s", &country2);
		printf("Number of migrators(milions):");
		scanf("%d", &pop);
		migration(&repo, country1, country2, pop);
	
	}
	else if (option == 5)
	{

		char subString[100];
		subString[0] = '\0';
		printf("Enter substring : ");
		scanf_s("%c", &subString[0]);
		printf("%s", subString);
		int i = -1;
		do
		{
			i++;
			scanf("%c", &subString[i]);
			subString[i + 1] = '\0';
		} while (subString[i] != '\n');
		subString[i] = '\0';
		Country* countriesFound;
		int nrElements = 0;
		countriesFound = searchByName(&repo, subString, &nrElements);
		for (int i = 0; i < nrElements; i++)
		{
			printf("%s, ", countriesFound[i].name);
			printf("%s, ", countriesFound[i].continent);
			printf("%d \n", countriesFound[i].population);
		}

	}
	
	}
	

	_CrtDumpMemoryLeaks();

	return 0;

}