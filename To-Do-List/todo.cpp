#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<string> tasks;

void addTask() {
    string task;
    cout << "Enter a new task: ";
    cin.ignore(); // برای جلوگیری از خطای دریافت ورودی
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!\n";
}
void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet!\n";
        return;
    }
    cout << "----- Your Tasks -----\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    showTasks();
    if (tasks.empty()) return;

    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;

    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}
int main() {
    int choice;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: deleteTask(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

