#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;

    cout << "=== User Registration ===" << endl;
    cout << "Enter username: ";
    cin >> username;

    // Check if user already exists
    ifstream checkFile(username + ".txt");
    if (checkFile) {
        cout << "Username already exists. Try another one." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(username + ".txt");
    if (file) {
        file << username << endl << password;
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error: Could not create user file." << endl;
    }

    file.close();
}

void loginUser() {
    string username, password, storedUser, storedPass;

    cout << "=== User Login ===" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (!file) {
        cout << "User not found!" << endl;
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);
    file.close();

    if (storedUser == username && storedPass == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid credentials!" << endl;
    }
}

int main() {
    int choice;

    cout << "=== Login & Registration System ===" << endl;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}