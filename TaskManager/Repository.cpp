//
// Created by user on 26.04.2023.
//

#include "Repository.h"

Repository::Repository()=default;

int Repository::findTask(std::string description)
{
    int nr=size(tasks);
    for (int i=0;i<nr;i++)
        if(tasks[i].getDescription()==description)
            return i;
    return  -1;

}

void Repository::add(Task &task)
{
    tasks.push_back(task);
}

std::vector<Task> Repository::getAllTasks() const
{
    return tasks;
}

Repository::~Repository()=default;