//
// Created by user on 26.04.2023.
//

#include "domain.h"

Task::Task():description{ "" },duration{ 0 },priority{ 0 }
{
}

Task::Task(const std::string & _description, const int _duration, const int _priority): description{_description},duration{_duration},priority{_priority}
{

}

Task::Task(const Task &task)
{
    this->description=task.description;
    this->duration=task.duration;
    this->priority=task.priority;
}

std::string Task::getDescription() const
{
    return this->description;
}

int Task::getDuration() const
{
    return this->duration;
}

int Task::getPriority() const
{
    return this->priority;
}

std::string Task::toString() const
{
    auto durationStr = std::to_string(duration);
    auto priorityStr = std::to_string(priority);
    return this->description+" | "+ durationStr + " | "+priorityStr;

}

Task::~Task()=default;