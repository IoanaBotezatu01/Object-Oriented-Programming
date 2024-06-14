//
// Created by user on 27.04.2023.
//

#include "Repository.h"

Repository::Repository() =default;

void Repository::add(Protein &protein)
{
    proteins.push_back(protein);
}

std::vector<Protein> Repository::getAll() const
{
    return proteins;
}

int Repository::findProtein(std::string organism, std::string name)
{
int cnt=size(proteins);
for(int i=0;i<cnt;i++)
    if(proteins[i].getOrganism()==organism&&proteins[i].getName()==name)
        return i;
    return -1;
}

void Repository::remove(Protein &protein)
{
//
// * nt cnt=size(proteins);
//    for(int i=0;i<cnt;i++)
//        if(proteins[i].getSequence()==protein.getSequence()&&proteins[i].getOrganism()==protein.getOrganism()&&proteins[i].getName()==protein.getName())
//            proteins.erase(i,i);

}

Repository::~Repository() =default;
