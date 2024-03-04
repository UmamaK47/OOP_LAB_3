#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        }
        else {
            cout << "Tasks in the list:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << (i + 1) << ". ";
                if (tasks[i]->completed) {
                    cout << "[Completed] ";
                }
                cout << tasks[i]->description << endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1]->completed = true;
            cout << "Task " << index << " marked as completed." << endl;
        }
        else {
            cout << "Invalid task index." << endl;
        }
    }

    ~ToDoList() {
        for (auto& task : tasks) {
            delete task;
        }
    }
};

int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Submit Assignment");
    myList.addTask("Prepare for Exam");

    myList.listTasks();

    cout << "\nMarking task 1 as completed..." << endl;
    myList.markTaskCompleted(1);

    myList.listTasks();

    return 0;
}