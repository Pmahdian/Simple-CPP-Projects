#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;
    bool running = true;

    cout << "=== Simple C++ Calculator ===" << endl;
    cout << "----------------------------" << endl;

    while (running) {
        // Get user input
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        // Exit condition
        if (operation == 'q' || operation == 'Q') {
            cout << "Exiting calculator..." << endl;
            running = false;
            continue;
        }

        cout << "Enter second number: ";
        cin >> num2;

        // Perform calculation
        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operator!" << endl;
        }
        cout << "----------------------------" << endl;
    }

    return 0;
}