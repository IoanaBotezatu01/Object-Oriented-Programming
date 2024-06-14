//
// Created by user on 26.04.2023.
//

#ifndef TASKMANAGER_SERVICE_H
#define TASKMANAGER_SERVICE_H

#include "domain.h"
#include "Repository.h"

class Service{
private:
    Repository& repo;
public:
    explicit Service(Repository& repo);
    int add(std::string description, int duration, int priority);
    std::vector<Task> getAllTasks();
    std::vector<Task> sort();
    int PriorityTime(int priority);
    ~Service();

};


#endif //TASKMANAGER_SERVICE_H
