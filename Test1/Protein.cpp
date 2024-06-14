//
// Created by user on 27.04.2023.
//

#include "Protein.h"

Protein::Protein():organism{""},name{""},sequence{""}
{
}

Protein::Protein(const std::string& _organism, const std::string& _name, const std::string& _sequence) :organism{_organism},name{_name},sequence{_sequence}
{
}

Protein::Protein(const Protein &protein)
{
    this->name=protein.name;
    this->organism=protein.organism;
    this->sequence=protein.sequence;
}

std::string Protein::getOrganism()
{
    return this->organism;
}

std::string Protein::getName()
{
    return this->name;
}

std::string Protein::getSequence()
{
    return this->sequence;
}

std::string Protein::toString()
{
    return this->organism+" | "+ this->name+" | "+ this->sequence;
}

Protein::~Protein() =default;
