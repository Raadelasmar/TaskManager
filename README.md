# Task Manager Project (C++)

A console-based task manager application written in C++.

This program reads, displays, and manages tasks stored in a text file.

## 🚀 Features
- Reads tasks from `tasks.txt`
- Supports adding, deleting, updating, printing tasks
- Uses `Task` and `TaskGroup` classes
- Saves updated tasks back into the file
- Built and tested using Visual Studio 2022 on Windows

---

## 📂 Files included
- `Main.cpp` → main program file
- `Task.cpp` → task class implementation
- `Task.h` → task class header
- `TaskGroup.cpp` → task group class implementation
- `TaskGroup.h` → task group header
- `tasks.txt` → input text file with task data
- `Task Manager Documentation.pdf` → project documentation

---

## 🛠️ How to compile

### ✅ Using Visual Studio:
1. Open `Main.cpp` inside a new empty C++ project
2. Add `Task.cpp` and `TaskGroup.cpp` to project
3. Add `Task.h` and `TaskGroup.h` to header files
4. Build Solution
5. Executable will appear in `x64\Debug`

### ✅ Using g++ (Linux/Mac):
```bash
g++ -o TaskManager Main.cpp Task.cpp TaskGroup.cpp
./TaskManager
```


### 📏 How to run

Place tasks.txt in the same folder as the executable

 - Run the program

 - Program reads tasks from file → displays menu options for operations

✅ Any changes will be saved back into tasks.txt.


### 📝 Notes

 - tasks.txt must follow the expected format (one task per line, fields separated appropriately)

 - Designed and tested for Windows / Visual Studio environment
