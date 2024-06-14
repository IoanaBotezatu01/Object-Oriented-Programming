//
// Created by user on 27.04.2023.
//

#include "Service.h"

Service::Service(Repository &repo):repo{repo}
{
this->repo=repo;
}

void Service::remove(std::string name, std::string organism)
{   std::string sequence;
    auto pr=this->repo.getAll();
    int cnt=size(this->repo.getAll());
    for(int i=0;i<cnt;i++)
        if(pr[i].getName()==name&&pr[i].getOrganism()==organism)
            sequence=pr[i].getSequence();
Protein p=Protein(name,organism,sequence);
int res= this->repo.findProtein(organism,name);
if(res==-1)
    std::cout<<"This Protein does not exist!"<<std::endl;
else
{
    this->repo.remove(p);
    std::cout<<"Protein removed!"<<std::endl;
}

}

std::vector<Protein> Service::getAll()
{
    return this->repo.getAll();
}

Service::~Service() =default;
