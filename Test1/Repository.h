//
// Created by user on 27.04.2023.
//

#ifndef TEST1_REPOSITORY_H
#define TEST1_REPOSITORY_H
#include "vector";
#include "Protein.h"

class Repository {
private:
    std::vector<Protein> proteins;
public:
    Repository();
    //return the index of the protein if it exists,-1 otherwise
    int findProtein(std::string organism, std::string name);
    //adds the protein in the repository
    void add(Protein& protein);
    //removes the protein from the repository
    void remove(Protein& protein);
    std::vector<Protein> getAll() const;
    ~Repository();
};


#endif //TEST1_REPOSITORY_H
