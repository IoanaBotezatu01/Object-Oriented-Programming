//
// Created by user on 25.05.2023.
//

#include "Repository.h"
#include "fstream"
#include "iostream"
using namespace std;

void loadFromFile()
{
    ifstream f("Documents.txt");
    this->documents.clear();
    Document* currentDocument;
    while(f>>currentDocument)
        this->documents.push_back(currentDocument);

    fclose(f);
}