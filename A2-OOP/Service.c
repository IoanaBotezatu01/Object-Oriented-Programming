#include "Service.h"
#include "Repository.h"
#include "Country.h"
#include <stdlib.h>

/*

Service* createService(Repository* repo)
{
    Service* sv = (Service*)malloc(sizeof(Service));
    sv->repo = repo;
    return sv;
}
void destroyService(Service* s)
{
    if (s == NULL)
        return;
    destroyRepository(s->repo);
    free(s);
}
void addCountryFromService(Service* s, char* name, char* continent, double population)
{
    Country c = createCountry(name, continent, population);
    addEstate(s->repo, &c);
}

void deleteCountryFromService(Service* s, char* name)
{
    Country* c = getName(s->repo, name);
    deleteEstate(s->repo, c);
}

//void updateCountryFromService(Service* s, char* name, char* continent, double population)
//{
  //  Country c = createCountry(name, continent, population);
  //  updateCountry(s->repo,c.name,c.continent,c.population);
//}

*/
