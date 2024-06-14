//
// Created by user on 27.04.2023.
//

#ifndef TEST1_PROTEIN_H
#define TEST1_PROTEIN_H
#include "iostream"

class Protein {
private:
    std::string organism;
    std::string name;
    std::string sequence;
public:
    Protein();
    Protein(const std::string&,const std::string&, const std::string&);
    Protein( const Protein& protein);
    std::string getOrganism();
    std::string getName();
    std::string getSequence();
    std::string toString();

    ~Protein();
};


#endif //TEST1_PROTEIN_H
