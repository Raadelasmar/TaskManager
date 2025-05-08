#include "TaskGroup.h"
#include <iostream>
#include <cctype> // for isAlpha



using namespace std;

extern void clearInput();

TaskGroup::TaskGroup()
{
	totalnumberoftasks = 0;
	data = NULL;
}

TaskGroup::~TaskGroup()
{
	delete[] data;
}

void TaskGroup::addTask(Task task)
{
	Task* temp = new Task[totalnumberoftasks + 1]; // create a dynamically allocated array with size of totalnumoftasks + 1 ( for the new task)
	for (int i = 0; i < totalnumberoftasks; i++)
	{
		temp[i] = data[i];
	}
	temp[totalnumberoftasks] = task;
	delete[] data;
	data = temp; // make data point to whatever temp is pointing to
	totalnumberoftasks++;
}

void TaskGroup::deleteTask(int id, bool updateMode)
{
	if (!isTask(id)) {
		cout << "Task ID not found." << endl;
		clearInput();
		return;
	}

	Task* temp = new Task[totalnumberoftasks - 1];
	int j = 0;
	for (int i = 0; i < totalnumberoftasks; i++)
	{
		if (data[i].getID() != id)
		{
			temp[j] = data[i];
			j++;
		}
	}
	totalnumberoftasks--;
	delete[] data;
	data = temp;
	if (updateMode) // from main -> updatetask -> deletetask
	{
		cout << "Congrats on completing the task!" << endl;
	}
	else
	{
		cout << "Task Deleted Successfully!" << endl;
	}
}

void TaskGroup::printTasks(string filename) // this method will print the tasks to the file 
{
	ofstream file;
	file.open(filename);
	for (int i = 0; i < totalnumberoftasks; i++)
	{
		file << data[i].getID() << endl;   //// Write the ID of the task to the file
		file << data[i].getName() << endl;
		file << data[i].getPoriority() << endl;
		file << data[i].getNotes() << endl;
		file << data[i].getGroup() << endl;
		file << data[i].getCompleted() << endl;
		file << data[i].getDay() << endl;
		file << data[i].getMonth() << endl;
		file << data[i].getYear() << endl;
	}
	file.close();
}
bool TaskGroup::isTask(int id)
{
	for (int i = 0; i < totalnumberoftasks; i++)
	{
		if (data[i].getID() == id)
		{
			return true;
		}
	}
	return false;
}

void TaskGroup::displayAllTasks()
{
	for (int i = 0; i < totalnumberoftasks; i++)
	{
		if (data[i].getCompleted() == 0) {  // Only display if the task is not completed
			cout << "----------------------------------------" << endl;
			cout << "ID: " << data[i].getID() << endl;
			cout << "Name: " << data[i].getName() << endl;
			cout << "Priority: " << data[i].getPoriority() << endl;
			cout << "Notes: " << data[i].getNotes() << endl;
			cout << "Group: " << data[i].getGroup() << endl;
			cout << "Completed: " << data[i].getCompleted() << endl;
			cout << "Deadline Date: " << data[i].getDay() << "-" << data[i].getMonth() << "-" << data[i].getYear() << endl;
			cout << "----------------------------------------" << endl; // This line is added as a footer for each task.
		}
	}
}


void TaskGroup::updateTask(int id, int field) {
	int pos = 0;
	for (int i = 0; i < totalnumberoftasks; i++) {
		if (data[i].getID() == id) {
			pos = i;
			break;
		}
	}

	switch (field) {
	case 1: { // Name update
		cout << "Current name: " << data[pos].getName() << endl;
		cout << "Enter the new name: ";
		string name;
		getline(cin, name);

		// Check if the name contains only letters and spaces
		bool validName = !name.empty(); // Check if name is not empty as initial validation
		for (char c : name) { //// Iterate over each character 'c' in the string 'name'
			if (!isalpha(c) && c != ' ') {
				validName = false;
				break;
			}
		}

		while (!validName) {
			cout << "Invalid input. Please enter a name with only alphabetical characters and spaces: ";
			getline(cin, name);
			validName = true;
			for (char c : name) {
				if (!isalpha(c) && c != ' ') {
					validName = false;
					break;
				}
			}
		}
		data[pos].setName(name);
		cout << "Task name updated successfully!" << endl;
		break;
	}
	case 2: { // Priority update
		cout << "Current priority: " << data[pos].getPoriority() << endl;
		cout << "Enter the new priority: ";
		int priority;
		while (true) {
			cin >> priority;
			if (cin.fail()) {
				clearInput();
				cout << "Priority must be a positive number, please re-enter the priority: ";
			}
			else if (priority <= 0) {
				cout << "Priority must be positive, please enter a positive number: ";
			}
			else {
				break; // if the priority is a positive and valid number
			}
		}
		data[pos].setPoriority(priority);
		cout << "Task priority updated successfully!" << endl;
		break;
	}
	case 3:
	{
		cout << "Current notes: " << data[pos].getNotes() << endl;
		string notes;
		cout << "Enter the notes of the task: ";
		cin.clear();
		getline(cin, notes); // getline is used to prevent whitespace problems
		data[pos].setNotes(notes);
		cout << "Task notes updated successfully!" << endl;
		break;
	}
	case 4:
	{
		cout << "Current group: " << data[pos].getGroup() << endl;
		cout << "Enter the group of the task: ";
		cin.clear();
		string groupname;
		while (true) {
			getline(cin, groupname);
			// Convert input to lowercase for case-insensitive comparison
			string lowercaseGroupname = groupname;
			transform(lowercaseGroupname.begin(), lowercaseGroupname.end(), lowercaseGroupname.begin(), ::tolower); // start the transform operation from the start ot the end and replace it directly, the operation is tolower

			// Check if the input is one of the three allowed options
			if (lowercaseGroupname == "education" || lowercaseGroupname == "chores" || lowercaseGroupname == "health") {
				break;  // Valid input, exit the loop
			}
			else {
				cout << "Invalid group name. Please enter 'education', 'chores', or 'health': ";
			}
		}
		data[pos].setGroup(groupname);
		cout << "Task group updated successfully!" << endl;
		break;
	}
	case 5:
	{
		cout << "Current completion status: " << data[pos].getCompleted() << endl;
		cout << "Enter the completion status of the task (1 for completed, 0 for not completed): ";
		int completed;
		while (true) {
			cin >> completed;
			if (cin.fail()) {
				clearInput();
				cout << "Completion status must be 0 or 1, please re-enter the completion status: ";
			}
			else if (completed != 0 && completed != 1) {
				cout << "Completion status must be 0 or 1, please enter 0 or 1: ";
			}
			else {
				break;
			}
		}
		if (completed == 1)
		{
			this->deleteTask(id, true);
		}
		break;
	}
	case 6:
	{
		cout << "Current deadline date: " << data[pos].getDay() << "-" << data[pos].getMonth() << "-" << data[pos].getYear() << endl;
		int day, month, year;
		cout << "Enter the day of the task (1-31): ";

		// enter and validate the day
		while (!(cin >> day) || day < 1 || day > 31) {
			clearInput();
			cout << "Invalid day. Please enter a value between 1 and 31: ";
		}

		// Enter and validate the month
		cout << "Enter the month of the task (1-12): ";
		while (!(cin >> month) || month < 1 || month > 12) {
			clearInput();
			cout << "Invalid month. Please enter a value between 1 and 12: ";
		}

		// Enter and validate the year
		cout << "Enter the year of the task (must be greater than 2023): ";
		while (!(cin >> year) || year <= 2023) {
			clearInput();
			cout << "Invalid year. Please enter a year greater than 2023: ";
		}
		data[pos].setDay(day);
		data[pos].setMonth(month);
		data[pos].setYear(year);
		cout << "Task deadline date updated successfully!" << endl;
		break;
	}
	}
}

