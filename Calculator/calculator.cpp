#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

void pauseScreen(){
    cout << "Press Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for user to press Enter
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int choice;
    double num1, num2;
    bool running = true;

    while (running) {
        pauseScreen();
        clearScreen(); // Clear console screen for a clean look
        cout << "=== Simple C++ Calculator ===\n" << endl;
        
        cout << "Select what type of operation you want to perform: " << endl;
        cout << "1. Addition (m + n)." << endl;
        cout << "2. Subtraction (m - n)." << endl;
        cout << "3. Multiplication (m * n)." << endl;
        cout << "4. Division (m / n)." << endl;
        cout << "5. Power (m ^ n)." << endl;
        cout << "6. Square root (sqrt(n))." << endl;
        cout << "7. Logarithm (log(n))." << endl;
        cout << "0. Quit (\"0\" to exit)." << endl;
        cout << "> ";

        cin >> choice;

        if(cin.fail()){ // input validation
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue; 
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer incase user inputs float

        if(choice < 0 || choice > 7){
            cout << "Invalid selection!" << endl;
            continue;
        }

        // Exit condition
        if(choice == 0){
            cout << "Exiting calculator..." << endl;
            running = false;
            continue;
        }

        // Get user input
        cout << "Enter number: ";
        cin >> num1;

        if(cin.fail()){ // input validation
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue; 
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(choice >= 1 && choice <= 5){
            cout << "Enter number: ";
            cin >> num2;

            if(cin.fail()){ // input validation
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue; 
            }
        }

        // Perform calculation
        switch(choice){
            case 1:
                // Addition

                cout << "Result: " << num1 + num2 << endl;

                break;
            case 2:
                // Subtraction

                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                // Multiplication

                cout << "Result: " << num1 * num2 << endl;

                break;
            case 4:
                // Division

                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }

                break;
            case 5:
            {
                // Power

                if(num1 < 0 && floor(num2) != num2){
                    cout << "Error: Cannot calculate non-integer powers of negative numbers." << endl;
                    break;
                }

                if(num1 == 0 && num2 <= 0){
                    cout << "Error: Cannot calculate zero raised to zero or negative powers." << endl;
                    break;
                }

                double result = pow(num1, num2);

                if(isnan(result) || isinf(result)){
                    cout << "Error: Result is undefined or infinite!" << endl;
                    break;
                }

                cout << "Result: " << result << endl; 

                break;
            }
            case 6:
                // Square Root

                if(num1 >= 0){
                    cout << "Result: " << sqrt(num1) << endl;
                } else {
                    cout << "Error: Cannot calculate square root of a negative number!" << endl;
                }

                break;
            case 7:
                // Logarithm

                if(num1 > 0){
                    cout << "Result: " << log(num1) << endl;
                } else {
                    cout << "Error: Cannot calculate logarithm of a negative number or zero!" << endl;
                }
                
                break;
        }
        cout << "----------------------------" << endl;
    }

    return 0;
}