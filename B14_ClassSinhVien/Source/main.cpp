#include "classSinhVien.hpp"


int main() {
    StudentManager manager;

    int option;
    do {
        cout << "---------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add student." << endl;
        cout << "2. Update student by ID." << endl;
        cout << "3. Remove student by ID." << endl;
        cout << "4. Search students by name." << endl;
        cout << "5. Sort students by average score." << endl;
        cout << "6. Sort students by name." << endl;
        cout << "7. Display student list." << endl;
        cout << "0. Exit." << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                manager.addStudent();
                break;
            case 2: {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                manager.updateStudent(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                manager.removeStudent(id);
                break;
            }
            case 4: {
                string name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                manager.searchStudentsByName(name);
                break;
            }
            case 5:
                manager.sortStudentsByAverageScore();
                break;
            case 6:
                manager.sortStudentsByName();
                break;
            case 7:
                manager.displayStudents();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 0);

    return 0;
}