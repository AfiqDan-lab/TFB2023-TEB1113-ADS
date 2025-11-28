#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
};

int main() {
    Student student[5];

    cout << "--- Enter Student Details ---\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << (i + 1) << "\n";

        cout << "ID: ";
        cin >> student[i].id;

        cout << "Name: ";
        cin >> student[i].name;   
        cout << "Email: ";
        cin >> student[i].email;
    }

    cout << "\n Displaying Data \n";

    for (int i = 0; i < 5; i++) {
        cout << "Student " << (i + 1) << " details\n";
        cout << "ID: " << student[i].id << "\n";
        cout << "Name: " << student[i].name << "\n";
        cout << "Email: " << student[i].email << "\n\n";
    }

    return 0;
}
