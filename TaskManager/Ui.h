//
// Created by user on 26.04.2023.
//

#ifndef TASKMANAGER_UI_H
#define TASKMANAGER_UI_H


#include "Service.h"

class Ui{
private:
    Service& service;
public:
    explicit Ui(Service& service);
    void printMenu();
    void handleAdd();
    void handlePriority();
    void start();
    void print();
    ~Ui();
};


#endif //TASKMANAGER_UI_H
