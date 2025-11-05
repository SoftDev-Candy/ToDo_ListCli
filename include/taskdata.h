//
// Created by Candy on 9/13/25.
//

#ifndef CLITODOLIST_TASKDATA_H
#define CLITODOLIST_TASKDATA_H

#include<iostream>

class Task {
private:

    int id;
    std::string title;
    std::string description;
    std::string dateNtime;
    bool status;

public:
Task(){}

    void setId(int d);
    void setDone(bool d);
    void setTitle(std::string newTitle);
    void setDateNtime(std::string newDate);
    void setDescription(std::string stringSentence);
    int getId()const;
    std::string getTitle()const;
    bool getDone()const;
    std::string getDescription()const;
    std::string getDateNtime()const;

};


#endif
