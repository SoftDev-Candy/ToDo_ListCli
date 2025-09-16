//
// Created by Candy on 9/13/25.
//

#ifndef CLITODOLIST_TASKDATA_H
#define CLITODOLIST_TASKDATA_H

#include<iostream>

class Task {
private:

int id;
std::string description;
bool done;


public:
Task(){}

    void setId(int d);
    void setDescription(std::string stringSentence);
    void setDone(bool d);

};


#endif
