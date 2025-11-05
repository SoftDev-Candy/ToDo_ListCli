//
// Created by Candy on 10/28/25.
//

#include "../include/repository.h"

#include <algorithm>
#include <thread>

void Repo::AddTask(const Task &taskadd)
{
    dataRepository.push_back(taskadd);
}

void Repo::listTasks()const
{
    for(int i = 0; i < dataRepository.size(); i++)
    {
        std::cout<<dataRepository[i];
        std::cout<<std::endl;
        std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    }
}

void Repo::RepoUpdateStatus(const std::vector<int> &id, bool status)
{
    unsigned long size = id.size();
    for(int i = 0; i < size; i++)
    {
        int temp = id[i];
        dataRepository[temp].setDone(status);
    }
    std::cout<<"Updated "<<size<<" Tasks"<<std::endl;

}

void Repo::UpdateIdRepo(int id) {
    auto it = std::find_if(dataRepository.begin(), dataRepository.end(),
                           [id](const Task &task)
    {
        return task.getId() == id;
    });

    if (it != dataRepository.end())
    {
        std::cout<<"Add the new title you want for this id :";
        std::string newtitle;
        std::getline(std::cin,newtitle);

        std::cout<<"Add the new description you want for this id : ";
        std::string newdescription;
        std::getline(std::cin,newdescription);

        if (!newtitle.empty())
        {
            it -> setTitle(newtitle);
        }

        if (!newdescription.empty())
        {
            it -> setDescription(newdescription);
        }
    }
    else
    {
        std::cout<<"No tasks found"<<std::endl;
    }
}


void Repo::DeleteTaskRepo(std::vector<int> &id)
{
    unsigned long int size = id.size();
    //I HAVE NO IDEA WHAT KIND OF DEBAUCHERY THIS REALLY IS I DID MY BRAINCELLS IN HERE //
       dataRepository.erase(remove_if(dataRepository.begin(), dataRepository.end(),
           [id](const Task &task)
           {return(std::find(id.begin(), id.end(), task.getId()) != id.end());} //here we basically call this so we are able to find and erase that id ...i almost overloaded ==
           ),dataRepository.end());

    std::cout<<"Deleted "<<size<<" Tasks"<<std::endl;
}

void Repo::findTask(const std::string &findstr)
{
    std::vector<Task*>foundtask;
    for (int i = 0; i < dataRepository.size(); i++) {
        std::string taskLower = dataRepository[i].getTitle();
        std::transform(taskLower.begin(), taskLower.end(), taskLower.begin(), ::tolower);
        std::string desclower = dataRepository[i].getDescription();
        std::transform(desclower.begin(), desclower.end(), desclower.begin(), ::tolower);

        if (taskLower.find(findstr) != std::string::npos || desclower.find(findstr) != std::string::npos)
        {
            foundtask.push_back(&dataRepository[i]);
        }
}
if (!foundtask.empty())
    {
        for (int i = 0; i<foundtask.size(); i++)
        {
            std::cout<<*foundtask[i]<<std::endl;
        }
    }
}

//overloaded that operator
std::ostream & operator<<(std::ostream &os, const Task &task)
{
    os<<std::left<<std::setw(4)<<task.getId()
    <<std::setw(5)<<task.getTitle()
    <<std::setw(30)<<task.getDescription()
    <<std::setw(30)<<task.getDateNtime()
    <<std::setw(10)<<((task.getDone()) ?"✓" : "✗");

        return os;
}

