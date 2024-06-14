//
// Created by user on 27.04.2023.
//

#ifndef TEST1_UI_H
#define TEST1_UI_H
#include "Service.h"

class Ui {
private:
    Service& service;
public:
    explicit Ui(Service& service);
    void printMenu();
    void start();
    void handleRemove();
    void print();
    ~Ui();

};


#endif //TEST1_UI_H
