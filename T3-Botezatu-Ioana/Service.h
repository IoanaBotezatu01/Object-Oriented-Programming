//
// Created by user on 25.05.2023.
//

#ifndef T3_BOTEZATU_IOANA_SERVICE_H
#define T3_BOTEZATU_IOANA_SERVICE_H
#include "Repository.h"
#include "Document.h"
#include "vector"
class Service {
private:
    Repository* repo;
public:
    std::vector<Document*> getAll(){return this->repo->getAll();}
    void sort();



};


#endif //T3_BOTEZATU_IOANA_SERVICE_H
