//
// Created by user on 26.04.2023.
//
#include "iostream"
#include "Service.h"

Service::Service(Repository &repo):repo{repo}
{
    this->repo=repo;
}

int Service::add(std::string description, int duration, int priority)
{
    Task t=Task(description,duration,priority);
    if(repo.findTask(description)!=-1)
        return -1;
    else
    {
        repo.add(t);
        return 1;
    }


}

std::vector<Task> Service::getAllTasks()
{
    return repo.getAllTasks();
}

std::vector<Task> Service::sort() {
    auto tasks=Service::getAllTasks();
    for(int i=0;i<size(tasks)-1;i++)
                for(int j=i+1;j<size(tasks);j++)
                    if(tasks[i].getDuration()<tasks[j].getDuration())
                        std::swap(tasks[i],tasks[j]);
    return tasks;

}

int Service::PriorityTime(int priority)
{ int totaltime=0;
    auto tasks= Service::getAllTasks();
    for(auto i:tasks)
        if(i.getPriority()<=priority)
            totaltime=totaltime+i.getDuration();
    return totaltime;
}

Service::~Service() =default;