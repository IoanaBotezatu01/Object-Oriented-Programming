//
// Created by user on 26.04.2023.
//

#include "Ui.h"

Ui::Ui(Service &service):service{service}
{
}

void Ui::printMenu()
{
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Add a task."<<std::endl;
    std::cout<<"2.Print all tasks."<<std::endl;
    std::cout<<"3.Compute the total estimated time for the tasks having the priority less than a given priority."<<std::endl;

}

void Ui::start()
{
    while (true)
    {
        Ui::printMenu();
        std::cout<<"Choose an option:";
        int option;
        std::cin>>option;
        if (option==0)
            break;
        if(option==1)
            Ui::handleAdd();
        if(option==2)
            Ui::print();
        if(option==3)
            Ui::handlePriority();

    }
}

void Ui::handleAdd()
{
    std::cout<<"Description:";
    std::string description;
    std::cin>>description;
    std::cout<<"Duration:";
    int duration;
    std::cin>>duration;
    std::cout<<"Priority:";
    int priority;
    std::cin>>priority;
    int result=this->service.add(description,duration,priority);
    if (result==-1)
        std::cout<<"The task already exists!"<<std::endl;
    else if(result==1)
        std::cout<<"The task was added succesfully!"<<std::endl;

}

void Ui::print() {
    auto t= this->service.sort();
    for(auto i:t)
        std::cout<<i.toString()<<std::endl;

}

void Ui::handlePriority()
{
    std::cout<<"Choose the max priority:";
    int priority;
    std::cin>>priority;
    if(priority<=0)
        std::cout<<"The priority is invalid!"<<std::endl;
    else
    {
        int time= this->service.PriorityTime(priority);
        std::cout<<"The total estimated time is:"<<time<<std::endl;
    }

}

Ui::~Ui()=default;
