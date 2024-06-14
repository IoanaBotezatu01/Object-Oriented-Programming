//
// Created by user on 10.05.2023.
//

#include "Service.h"
#include "TurboEngine.h"
#include "ElectricEngine.h"
#include "Engine.h"
#include <fstream>

Engine *Service::createEngine(std::string engineType, std::string fuelType, int autonomy)
{
    if (engineType == "Turbo")
    {
        TurboEngine* engine = new TurboEngine(fuelType, 3000);
        return engine;
    }
    else if(engineType=="Electric")
    {
        ElectricEngine* engine=new ElectricEngine(autonomy,3000);
        return engine;
    }
}

double Service::addCar(std::string bodyStyle, std::string engineType, std::string fuelType, int autonomy)
{
    if(engineType=="Turbo")
    {
        auto engine=createEngine(engineType,fuelType,0);
        auto car=new Car(bodyStyle,engine);
        cars.push_back(car);
        return car->computePrice();
    }

    if(engineType=="Electric")
    {
        auto engine=createEngine(engineType,"",autonomy);
        auto car=new Car(bodyStyle,engine);
        cars.push_back(car);
        return car->computePrice();
    }
}

std::vector<Car *> Service::getCars()
{
    return this->cars;
}

void Service::writeToFile(std::string filename,double maxprice)
{

    std::ofstream f(filename);
    for(auto i:cars)
    if(i->computePrice()<=maxprice)
    {
        f << i->toString() << "\n";
    }
    f.close();
}

