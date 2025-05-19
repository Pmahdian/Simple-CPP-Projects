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
