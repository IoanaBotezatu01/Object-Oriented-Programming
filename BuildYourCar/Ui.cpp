//
// Created by user on 10.05.2023.
//

#include <iostream>
#include "Ui.h"

void Ui::printMenu()
{
    std::cout<<"0.Exit."<<std::endl;
    std::cout<<"1.Add a new car."<<std::endl;
    std::cout<<"2.Show all cars."<<std::endl;
    std::cout<<"3.Save to a file all the cars having price less than a given price."<<std::endl;
}

void Ui::start()
{

int option;
    while (true)
    {   Ui::printMenu();
        std::cout<<"Choose an option:";
        std::cin>>option;
        if(option==0)
            break;
        if(option==1)
            Ui::handleAdd();
        if(option==2)
            Ui::print();
        if(option ==3)
        {
            double maxprice;
            std::cout<<"Enter the maximum price:";
            std::cin>>maxprice;
            this->serv.writeToFile("cars.txt",maxprice);
        }

    }


}

void Ui::handleAdd()
{
    std::cout<<"choose a body style( Sedan/ Convertible):";
    std::string bodyStyle;
    std::cin>>bodyStyle;
    if(bodyStyle!="Sedan"&&bodyStyle!="Convertible")
        std::cout<<"Invalid body style!"<<std::endl;
    else
    {
        std::cout<<"Choose the engine type(Electric/Turbo):";
        std::string engineType;
        std::cin>>engineType;
        if(engineType!="Electric"&& engineType!="Turbo")
            std::cout<<"Invalid engine type!"<<std::endl;
        else
        {
            if(engineType=="Turbo")
            {
                std::cout<<"Choose a fuel type( gasoline/diesel):";
                std::string fuelType;
                std::cin>>fuelType;
                if(fuelType!="diesel"&&fuelType!="gasoline")
                    std::cout<<"Invalid fuel type!"<<std::endl;
                else
                {
                   auto price=this->serv.addCar(bodyStyle,engineType,fuelType,0);
                    std::cout<<"Price:"<<price<<std::endl;
                }


            }
            else if(engineType=="Electric")
            {
                std::cout<<"Enter the autonomy:";
                int autonomy;
                std::cin>>autonomy;
               auto price= this->serv.addCar(bodyStyle,engineType,"",autonomy);
               std::cout<<"Price:"<<price<<std::endl;
            }

        }
    }


}

void Ui::print()
{
for(auto c: this->serv.getCars())
    std::cout<<c->toString()<<std::endl;
}

Ui::Ui(Service& serv) : serv{serv} {}

