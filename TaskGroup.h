#pragma once
#include "Task.h"
#include <fstream>
#include <algorithm> // so i can be able to use "transform"

class TaskGroup
{
	Task* data;
	int totalnumberoftasks;
public:
	TaskGroup();
	~TaskGroup();
	void addTask(Task task);
	void deleteTask(int id, bool updateMode);
	void printTasks(std::string filename); // print tasks to the file
	void updateTask(int id, int fieldNumber);
	bool isTask(int id);
	void displayAllTasks();
};
