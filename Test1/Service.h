//
// Created by user on 27.04.2023.
//

#ifndef TEST1_SERVICE_H
#define TEST1_SERVICE_H
#include "Protein.h"
#include "vector"
#include "Repository.h"
class Service {
private:
    Repository& repo;
public:
    explicit Service(Repository& repo);
    //removes the protein
    void remove(std::string name,std::string organism);
    std::vector<Protein> getAll();
    ~Service();

};


#endif //TEST1_SERVICE_H
