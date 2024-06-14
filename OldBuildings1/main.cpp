#include <iostream>
#include "Service.h"
#include "Ui.h"
#include "House.h"
#include "Block.h"
#include "Building.h"
int main() {
    Service service;
    Ui ui(service);
    House* house1=new House("Macesului-12",1980,false);
    Block* block1=new Block("Transilvaniei-4",2003,60,48);
    House* house2=new House("Unirii-20",1970,true);
    Block* block2=new Block("Gheorghe-Dima-4",1997,30,12);
    service.addBuilding(house1);
    service.addBuilding(block1);
    service.addBuilding(house2);
    service.addBuilding(block2);
    ui.start();
}
