#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

vector<Contact> contacts;

void loadContacts() {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        Contact c;
        while (file >> c.name >> c.phone) {
            contacts.push_back(c);
        }
        file.close();
    }
}
void saveContacts() {
    ofstream file("contacts.txt");
    for (const auto& c : contacts) {
        file << c.name << " " << c.phone << endl;
    }
    file.close();
}

void addContact() {
    Contact c;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone: ";
    cin >> c.phone;
    contacts.push_back(c);
    saveContacts();
    cout << "Contact added!\n";
}

void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts found!\n";
        return;
    }
    cout << "----- Contacts -----\n";
    for (int i = 0; i < contacts.size(); i++) {
        cout << i+1 << ". " << contacts[i].name << " - " << contacts[i].phone << endl;
    }
}