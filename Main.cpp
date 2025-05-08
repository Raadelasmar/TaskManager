#include <fstream>
#include <iostream>
#include "Task.h"
#include "TaskGroup.h"
#include <limits>
#include <cctype> // For isalpha function
#include <algorithm>


using namespace std;

void clearInput() {
    cin.clear();  // clear the error state of the input stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // used to ignore characters in the input buffer and specifies how many charachters to ignore
}

int main()
{
    TaskGroup group; // this is like a list of tasks
    int id, poriority, day, month, year;
    string name, notes, groupname;
    bool completed;
    ifstream infile;
    ofstream outfile;
    infile.open("tasks.txt");
    try {
        if (!infile.is_open())
            throw "File not opened";
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    //loading from the file, it will not stop unless it can't read an ID
    while (infile >> id) { // Read the integer ID
        infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        getline(infile, name); // Read the name
        infile >> poriority; // Read the integer priority
        infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        getline(infile, notes); // Read the notes
        getline(infile, groupname); // Read the group name
        infile >> completed; // Read the boolean completed
        infile >> day >> month >> year; // Read the integers day, month, year

        // Clear the newline character after the year
        infile.ignore(numeric_limits<streamsize>::max(), '\n');

        Task temptask(id, name, poriority, notes, groupname, completed, day, month, year);
        // Call static method increaseCount() on the Task class
        Task::increaseCount();
        group.addTask(temptask);
    }

    infile.close(); // Close the file after reading
    int choice = 0;
    cout << "     Welcome to your Task Manager!  " << endl;
    while (choice != 5)
    {
        cout << "----------------------------------------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Update Task" << endl;
        cout << "4. Display all tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a number from 1 to 5: ";
        }
        cout << "----------------------------------------" << endl;
        switch (choice) {
        case 1: {
            cout << "            Add New Task        " << endl;  // Title for adding task
            cout << "----------------------------------------" << endl;
            cout << "Enter a unique id of the task: ";
            // logic to make sure the id is unique you already have a function to check if the id exists
            while (true) {
                cin >> id;
                if (cin.fail()) {  // Check if the input was not an integer
                    clearInput();
                    cout << "The ID can only be a positive number, please re-enter the ID: ";  // Prompt the user again for a number
                }
                else if (id <= 0) {  // Check if the number is not positive
                    cout << "ID can't be negative or zero, please enter a positive number: ";
                }
                else {
                    break;  // Exit the loop if the number is a positive integer
                }
            }
            // additional code to check for unique ID
            if (group.isTask(id)) {
                cout << "A task with this ID already exists. Please enter a unique ID." << endl;
                break; // Break out of the case if the ID is not unique
            }
            cout << "Enter the name of the task: ";
            cin.ignore(); // to consume any newline left in the input buffer
            getline(cin, name);

            // Check if the name contains only letters and spaces
            bool validName = true;
            for (char c : name) { // check every charachter of name
                if (!isalpha(c) && c != ' ') { // Check if the character is not a letter or space
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

            cout << "Enter the priority of the task: ";
            while (true) {
                cin >> poriority;
                if (cin.fail()) { // Check if the input was not an integer
                    clearInput();
                    cout << "Priority must be a positive number, please re-enter the priority: ";
                }
                else if (poriority <= 0) { // Ensure the priority is positive
                    cout << "Priority must be positive, please enter a positive number: ";
                }
                else {
                    break; // Exit the loop if the input is a valid positive integer
                }
            }
            cout << "Enter the notes of the task: ";
            cin.ignore(); // to consume any newline left in the input buffer
            getline(cin, notes);
            cout << "Enter the group of the task (Options: 'education', 'chores', 'health'): ";
            while (true) {
                getline(cin, groupname);
                // Convert input to lowercase for case-insensitive comparison
                string lowercaseGroupname = groupname;
                transform(lowercaseGroupname.begin(), lowercaseGroupname.end(), lowercaseGroupname.begin(), tolower);

                // Check if the input is one of the three allowed options
                if (lowercaseGroupname == "education" || lowercaseGroupname == "chores" || lowercaseGroupname == "health") {
                    break;  // Valid input, exit the loop
                }
                else {
                    cout << "Invalid group name. Please enter 'education', 'chores', or 'health': ";
                }
            }

            cout << "Enter the day of the task (1-31): ";
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
            Task temptask(id, name, poriority, notes, groupname, false, day, month, year);
            // assuming Task has a function to increase count
            temptask.increaseCount();
            group.addTask(temptask);
            cout << "Task Added Successfully!" << endl;
            break;
        }
        case 2: {
            cout << "            Delete Task     " << endl;  // Title for deleting task
            cout << "----------------------------------------" << endl;
            cout << "Enter the id of the task you want to delete: ";
            cin >> id;
            // to clear the input buffer
            cin.clear();
            // logic to make sure the id exists before attempting to delete
            group.deleteTask(id, false);

            break;
        }
        case 3: {
            cout << "            Update Task     " << endl;  // Title for updating task
            cout << "----------------------------------------" << endl;
            cout << "Enter the id of the task you want to update: ";
            while (true) {
                cin >> id;
                if (cin.fail()) {  // Check if the input was not an integer
                    clearInput();
                    cout << "The ID can only be a positive number, please re-enter the ID: ";  // asks the user again for a number
                }
                else if (id <= 0) {  // Check if the number is not positive
                    cout << "ID can't be negative or zero, please enter a positive number: ";
                }
                else {
                    break;  // Exit the loop if the number is a positive integer
                }
            }
            if (group.isTask(id)) {  // to make sure that the ID exists 
                cout << "1. Name" << endl;
                cout << "2. Priority" << endl;
                cout << "3. Notes" << endl;
                cout << "4. Group" << endl;
                cout << "5. Completion Status" << endl;
                cout << "6. Deadline Date" << endl;
                cout << "Enter the number of the field you want to update: " << endl;
                int field;
                while (true)
                {
                    cin >> field;
                    if (field < 1 || field > 6) {
                        clearInput();
                        cout << "Invalid field number, please enter again: " << endl;
                    }
                    else {
                        clearInput();
                        group.updateTask(id, field);
                        break;
                    }
                }
            }
            else {

                cout << "Task ID does not exist." << endl;
            }

            break;
        }

        case 4:
            cout << "            Display All Tasks       " << endl;  // Title for displaying tasks
            cout << "----------------------------------------" << endl;
            group.displayAllTasks();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    group.printTasks("tasks.txt");
    outfile.close();
    infile.close();
    return 0;
}