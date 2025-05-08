#pragma once
#include <iostream>
#include <string> 


class Task
{
	int id;
	int poriority;
	std::string name;
	int day;
	int month;
	int year;
	std::string notes;
	bool completed;
	std::string group;
	static int numoftasks;
public:
	Task();
	Task(int id, std::string name, int poriority, std::string notes, std::string group, bool completed, int day, int month, int year);
	int getPoriority();
	std::string getName();
	int getDay();
	int getMonth();
	int getYear();
	std::string getNotes();
	bool getCompleted();
	std::string getGroup();
	int getID();
	void setID(int id);
	void setPoriority(int poriority);
	void setName(std::string name);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setNotes(std::string notes);
	void setCompleted(bool completed);
	void setGroup(std::string group);
	static void increaseCount();
};

