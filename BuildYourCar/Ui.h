//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_UI_H
#define BUILDYOURCAR_UI_H
#include "Service.h"

class Ui {
private:
    Service& serv;
public:
    explicit Ui(Service& serv);
    void printMenu();
    void start();
    void handleAdd();
    void print();


};


#endif //BUILDYOURCAR_UI_H
