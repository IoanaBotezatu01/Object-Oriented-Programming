//
// Created by user on 26.04.2023.
//

#ifndef TASKMANAGER_REPOSITORY_H
#define TASKMANAGER_REPOSITORY_H

#include <vector>
#include "domain.h"

class Repository {
private:
    std::vector<Task> tasks;
public:
    Repository();

    int findTask(std::string description);
    void add(Task& task);
    std::vector<Task> getAllTasks() const;

    ~Repository();

};


#endif //TASKMANAGER_REPOSITORY_H
