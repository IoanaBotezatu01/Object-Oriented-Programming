//
// Created by user on 27.04.2023.
//

#include "Ui.h"

Ui::Ui(Service &service) :service{service}
{
}

void Ui::printMenu() {
    std::cout<<"0.Exit."<<std::endl;
    std::cout<<"1.Remove protein"<<std::endl;
    std::cout<<"2.Print all proteins."<<std::endl;
    std::cout<<"3.Show all proteins that contain a given sequence in their name."<<std::endl;

}

void Ui::start() {
    while (true)
    {
        Ui::printMenu();
        std::cout<<"Choose an option:";
        int option;
        std::cin>>option;
        if (option==0)
            break;
        if(option==1)
            Ui::handleRemove();
        if(option==2)
            Ui::print();

    }

}

void Ui::handleRemove()
{
    std::cout<<"Enter the organism";
    std::string organism;
    std::cin>>organism;
    std::cout<<"Enter the name:";
    std::string name;
    std::cin>>name;
    this->service.remove(name,organism);



}

void Ui::print()
{
auto proteins= this->service.getAll();
for(auto i:proteins)
    std::cout<<i.toString()<<std::endl;
}

Ui::~Ui() =default;