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