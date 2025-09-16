//
// Created by Candy on 9/16/25.
//

#include "../include/command.h"
void TaskCommands::startLoop()
{
    while(true)
    {
        std::cout<<"Todo>"<<std::endl;
        Input();

        if(command == "exit")
        {
            std::cout<<"Exiting..."<<std::endl;
        }
        else if (command == "add")
        {

        }
    }
}

std::string TaskCommands::Input()
{
    std::getline(std::cin,command);
    return command;
}
