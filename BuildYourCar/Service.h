//
// Created by user on 10.05.2023.
//

#ifndef BUILDYOURCAR_SERVICE_H
#define BUILDYOURCAR_SERVICE_H
#include "Engine.h"
#include "Car.h"
#include "vector"

class Service {
private:
    std::vector<Car*> cars;
public:


    ~Service() {};
    Engine* createEngine(std::string engineType,std::string fuelType,int autonomy);
    double addCar(std::string bodyStyle, std::string engineType,std::string fuelType,int autonomy);
    std::vector<Car*> getCarsWithMaxPrice(double maxPrice());
    void writeToFile(std::string filename,double maxprice);
    std::vector<Car*> getCars();


};


#endif //BUILDYOURCAR_SERVICE_H
