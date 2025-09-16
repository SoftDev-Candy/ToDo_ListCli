//
// Created by Candy on 9/16/25.
//

#ifndef CLITODOLIST_COMMAND_H
#define CLITODOLIST_COMMAND_H
#include <iostream>

class TaskCommands {
private:
    std::string command;

public:
    void startLoop();
    std::string Input();
};


#endif //CLITODOLIST_COMMAND_H