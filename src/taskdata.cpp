//
// Created by Candy on 9/13/25.
//
#include"taskdata.h"

void Task::setId(int value)
{
    id = value;
}

void Task::setDescription(std::string stringSentence)
{
    description = stringSentence ;
}



void Task::setDone(bool d)
{
    status= d ;
}

void Task::setTitle(std::string newTitle)
{
    title = newTitle;
}

void Task::setDateNtime(std::string newDate)
{
    dateNtime = newDate;
}

int Task::getId()const
{
    return id;
}

std::string Task::getTitle()const
{
 return title;
}

bool Task::getDone()const
{
    return status;
}

std::string Task::getDescription()const
{
    return description;
}

std::string Task::getDateNtime()const
{
    return dateNtime;
}
