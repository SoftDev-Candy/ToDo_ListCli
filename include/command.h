//
// Created by Candy on 9/16/25.
//

#ifndef CLITODOLIST_COMMAND_H
#define CLITODOLIST_COMMAND_H

#include"repository.h"
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include<ctime>
#include<cctype>
#include<iomanip>
#include "taskdata.h"

class TaskCommands {
private:
    std::string command  ;

public:
    void StartLoop();
    std::string Input();
    void Add(int &val);
    void UpdateStatus();
    void UpdateId();
    void DeleteTask();

    //Declared objects in class
    Repo repo;
    Task task;
};

#endif //CLITODOLIST_COMMAND_H