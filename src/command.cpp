//
// Created by Candy on 9/16/25.
//

#include "../include/command.h"

#include <algorithm>
#include <iomanip>

void TaskCommands::StartLoop()
{
	int val = 0;
	std::cout<<"Welcome to simple todo app ^o^"<<std::endl;
	while(true)
	{
		Input();

		if(command == "exit")
		{
			std::cout<<"Exiting..."<<std::endl;
			break;
		}
		else if (command == "add")
		{
			std::cout<<"Todo>";
			Add(val);
		}
		else if (command == "findtask")
		{
			std::cout<<"Enter the name of the task you want to find :";
			std::string temp;
			std::getline(std::cin,temp);
			std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
			repo.findTask(temp);
		}
		else if (command == "listall")
		{
		repo.listTasks();
		}
		else if (command == "deletetask")
		{

			DeleteTask();
		}
		else if (command == "updateid")
		{
			UpdateId();
		}
		else if (command == "updatestatus")
		{
			UpdateStatus();

		}
		else {
			std::cout<<"Invalid command"<<std::endl;
		}
	}
}

std::string TaskCommands::Input()
{
	std::getline(std::cin,command);
	return command;
}

void TaskCommands::Add(int& val)
{
	Task objectsetter;

	std::cout<<"Adding task"<<std::endl;

	std::cout<<"Add title"<<std::endl;
	std::string tempTitle;
	std::getline(std::cin,tempTitle);

	std::cout<<"Add Description"<<std::endl;
	std::string description;
	std::getline(std::cin,description);

	//Taking converting and storing current time here//
	std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();// Calling the current time here
	std::time_t now_c = std::chrono::system_clock::to_time_t(startTime); //converting it into time_t
	std::tm* local_tm = std::localtime(&now_c);
	std::ostringstream oss{};
	oss<<std::put_time(local_tm,"%Y-%m-%d %H:%M:%S");
	std::string dateNtime = oss.str();

	//status and IdValue//
	bool status =false;

	objectsetter.setTitle(tempTitle);
	objectsetter.setDescription(description);
	objectsetter.setDateNtime(dateNtime);
	objectsetter.setDone(status);
	objectsetter.setId(val);

	repo.AddTask(objectsetter);
	val++;
	std::cout<<"Task added"<<std::endl;

}

void TaskCommands::UpdateStatus()
{
	std::cout<<"Enter the Command ""done"" and add the numbers in a series with space eg. 1 2 4 "<<std::endl;

	std::vector<int>idArray;
	std::string status;
	std::getline(std::cin,status);
	std::stringstream ss(status);
	std::string command;
	ss>>command;

	if (command == "done") {
		int id ;
		while (ss >> id) {
			idArray.push_back(id);
		}
		repo.RepoUpdateStatus(idArray,true);
	}

	else if (command == "notdone")
	{
		int id ;
		while (ss >> id) {
			idArray.push_back(id);
		}
		repo.RepoUpdateStatus(idArray,false);
	}
	else
	{
		std::cout<<"Invalid command 'Command Example - ""done 1 2 3 ""'"<<std::endl;
	}

}

void TaskCommands::UpdateId()
{
	std::cout<<"Enter Id of the task you to update : ";
	int id;
	std::cin>> id;
	repo.UpdateIdRepo(id);
}

void TaskCommands::DeleteTask()
{
	std::vector<int>deleteid;
	std::cout<<"Enter the Command ""delete"" and add the numbers in a series with space eg. 1 2 4 "<<std::endl;

	std::string deletetemp;
	std::getline(std::cin,deletetemp);
	std::stringstream ss(deletetemp);
	std::string commandtemp;
	ss>>commandtemp;

	if (commandtemp == "delete")
	{
		int id;
		while (ss>>id)
		{
			deleteid.push_back(id);
		}
		repo.DeleteTaskRepo(deleteid);
	}
	else
	{
		std::cout<<"Invalid command 'Command Example - ""delete 1 2 3 ""'"<<std::endl;
	}

}





