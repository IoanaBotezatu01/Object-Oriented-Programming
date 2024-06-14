//
// Created by user on 10.05.2023.
//
#include <fstream>
#include "Service.h"
#include "Ui.h"
#include "string"
#include "iostream"

void Ui::printMenu()
{
    std::cout<<"0.Exit."<<std::endl;
    std::cout<<"1.Add a new building."<<std::endl;
    std::cout<<"2.Show all buildings."<<std::endl;
    std::cout<<"3.Show all buildings that must be restored,older than a given year."<<std::endl;
    std::cout<<"4.Save all buildings that must be restored to a file,and those that can be demolished to another file."<<std::endl;
}

Ui::Ui(Service& service): service(service) {}

void Ui::start()
{
int option;
    while (true)
    {
        Ui::printMenu();
        std::cout<<"Choose an option:";
        std::cin>>option;
        if(option==0)
            break;
        if(option==1)
            this->handleAdd();
        if(option==2)
            this->print();
        if(option==3)
            this->printRestored();
        if(option==4)
            this->saveToFile();
    }

}

void Ui::handleAdd()
{
std::cout<<"Choose the type of building(house/block):";
std::string type;
std::cin>>type;
if(type!="house"&&type!="block")
    std::cout<<"Invalid type!"<<std::endl;
else
{
    std::string address;
    std::cout<<"Enter the address:";
    std::cin>>address;
    std::cout<<"Enter the construction year:";
    int year;
    std::cin>>year;
    if(type=="house")
    {

        std::string isHistorical;
        std::cout<<"Is the house historical?(true/false):";
        std::cin>>isHistorical;
        if(isHistorical!="false" && isHistorical!= "true")

            std::cout<<"Invalid value!"<<std::endl;
        else
        {   if(isHistorical=="true")
            {
                House* house=new House(address,year,true);
                this->service.addBuilding(house);
            }
            if(isHistorical=="false")
            {
                House* house=new House(address,year,false);
                this->service.addBuilding(house);
            }

        }

    }
    if(type=="block")
    {
        int total,occupied;
        std::cout<<"Choose the total number of apartments:";
        std::cin>>total;
        std::cout<<"Choose the number of occupied apartments:";
        std::cin>>occupied;
        if(total<=0||occupied<0)
            std::cout<<"Can't enter negative numbers!"<<std::endl;
        else
        {
            Block* block=new Block(address,year,total,occupied);
            this->service.addBuilding(block);
        }
    }

}
}

void Ui::print()
{
    for (auto b: this->service.getAllBuildings())
        std::cout<<b->toString()<<std::endl;
}

void Ui::printRestored()
{
    int year;
    std::cout<<"Enter a construction year:";
    std::cin>>year;
    for(auto i: this->service.getAllToBeRestored())
        if(i->getYear()<year)
            std::cout<<i->toString()<<std::endl;

}

void Ui::saveToFile()
{
    std::ofstream restored("restored.txt");
    std::ofstream demolished("demolished.txt");
    for(auto i: this->service.getAllToBeRestored())
        restored<<i->toString()<<std::endl;
    for(auto i: this->service.getAllToBeDemolished())
        demolished<<i->toString()<<std::endl;
    restored.close();
    demolished.close();

}
