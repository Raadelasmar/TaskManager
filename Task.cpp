#include "Task.h"
#include <iostream>


using namespace std;

Task::Task()
{
	id = 0;
	poriority = 0;
	name = "";
	day = 0;
	month = 0;
	year = 0;
	notes = "";
	completed = false;
	group = "";
}

Task::Task(int id, string name, int poriority, string notes, string group, bool completed, int day, int month, int year)
{
	this->id = id;
	this->name = name;
	this->poriority = poriority;
	this->notes = notes;
	this->group = group;
	this->completed = completed;
	this->day = day;
	this->month = month;
	this->year = year;
}

int Task::getPoriority()
{
	return poriority;
}

string Task::getName()
{
	return name;
}

int Task::getDay()
{
	return day;
}

int Task::getMonth()
{
	return month;
}

int Task::getYear()
{
	return year;
}

string Task::getNotes()
{
	return notes;
}

bool Task::getCompleted()
{
	return completed;
}

string Task::getGroup()
{
	return group;
}

int Task::getID()
{
	return id;
}

void Task::setID(int id)
{
	this->id = id;
}

void Task::setPoriority(int poriority)
{
	this->poriority = poriority;
}

void Task::setName(string name)
{
	this->name = name;
}

void Task::setDay(int day)
{
	this->day = day;
}

void Task::setMonth(int month)
{
	this->month = month;
}

void Task::setYear(int year)
{
	this->year = year;
}

void Task::setNotes(string notes)
{
	this->notes = notes;
}

void Task::setCompleted(bool completed)
{
	this->completed = completed;
}

void Task::setGroup(string group)
{
	this->group = group;
}
void Task::increaseCount()
{
	numoftasks++;
}
int Task::numoftasks = 0;