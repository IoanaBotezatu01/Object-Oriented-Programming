//
// Created by user on 26.04.2023.
//

#ifndef TASKMANAGER_DOMAIN_H
#define TASKMANAGER_DOMAIN_H
#include "iostream"
#include "string"

class Task {
private:
    std::string description;
    int duration;
    int priority;
public:
    Task();
    Task(const std::string&,const int ,const int);
    Task(const Task& task);

    std::string getDescription() const;
    int getDuration() const;
    int getPriority() const;

    std::string toString() const;
    ~Task();

};


#endif //TASKMANAGER_DOMAIN_H
