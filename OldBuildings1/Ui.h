//
// Created by user on 10.05.2023.
//

#ifndef OLDBUILDINGS1_UI_H
#define OLDBUILDINGS1_UI_H
#include "Service.h"

class Ui {
private:
    Service& service;
public:
    explicit Ui(Service& service);
    void printMenu();
    void handleAdd();
    void start();
    void print();
    void printRestored();
    void saveToFile();


};


#endif //OLDBUILDINGS1_UI_H
