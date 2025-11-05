//
// Created by Candy on 10/28/25.
//

#ifndef CLITODOLIST_REPOSITORY_H
#define CLITODOLIST_REPOSITORY_H

#include <vector>
#include <sstream>
#include <algorithm>
#include<iomanip>
#include "taskdata.h"



class Repo
{
public:
    void AddTask(const Task& taskadd);
    void listTasks()const;
    void RepoUpdateStatus( const std::vector<int> &id , bool status);
    void UpdateIdRepo(int id);
    void DeleteTaskRepo( std::vector<int> &id );
    void findTask(const std::string &task);
    Task task;

private:
    std::vector<Task>dataRepository;

};
std::ostream &operator<<(std::ostream &os, const Task &task);

#endif //CLITODOLIST_REPOSITORY_H