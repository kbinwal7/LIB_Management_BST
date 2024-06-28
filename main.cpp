#include <iostream>
#include "library.h"
using namespace std;

int main() {
    int n;
    cout << "Your Student ID: ";
    cin >> n;
    createLIB();
    nodeS* sNode = studentData->searchID(studentData->root, n);
    if (sNode != nullptr && sNode->stu.issued < 2) {
        studentRequest obj(n);
        bool loggedIn = true;

        while (loggedIn) {
            cout << "What do you want to do?\n";
            cout << "1. Check Availability of a book.\n";
            cout << "2. Issue a book.\n";
            cout << "3. Return a book.\n";
            cout << "0. Logout\n";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    int id;
                    cout << "The bookID: ";
                    cin >> id;
                    obj.checkAvailaiblity(id);
                    break;
                }
                case 2: {
                    int id;
                    cout << "ID of book to be issued: ";
                    cin >> id;
                    obj.requestIssue(id);
                    break;
                }
                case 3: {
                    int id;
                    cout << "ID of book to be returned: ";
                    cin >> id;
                    obj.requestReturn(id);
                    break;
                }
                case 0:
                    loggedIn = false;
                    cout << "Logged out. Have a great day!\n";
                    break;
                default:
                    cout << "Invalid choice. Please select a valid option.\n";
            }
        }
    } else {
        cout << "ISSUING LIMIT EXCEEDED or INVALID STUDENT ID!\n";
    }
    return 0;
}
