//
// Created by user on 25.05.2023.
//

#ifndef T3_BOTEZATU_IOANA_REPOSITORY_H
#define T3_BOTEZATU_IOANA_REPOSITORY_H

#include "vector"
#include "Document.h"

class Repository {
private:
    std::vector<Document*> documents;
public:
    Repository()=default;
    std::vector<Document*> getAll() {return this->documents;}
    void loadFromFile();
    ~Repository()=default;
};


#endif //T3_BOTEZATU_IOANA_REPOSITORY_H
