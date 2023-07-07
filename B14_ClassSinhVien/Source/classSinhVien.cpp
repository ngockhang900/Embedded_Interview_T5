#include "classSinhVien.hpp"


Student::Student(){ 
    string name, gender;
    int age;
    double mathScore, physicsScore, chemistryScore;
    this->id = idCounter++;
    this->name = name;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->mathScore = mathScore;
    this->physicsScore = physicsScore;
    this->chemistryScore = chemistryScore;
    this->averageScore = (mathScore + physicsScore + chemistryScore) / 3;
    this->academicPerformance = calculateAcademicPerformance();
}
int Student::idCounter = 1;

int Student::getID() const{
    return id;
}
string Student::getName()const {
        return name;
}

string Student::getGender()const {
    return gender;
}

int Student::getAge() const{
    return age;
}

double Student::getMathScore()const {
    return mathScore;
}

double Student::getPhysicsScore() {
    return physicsScore;
}

double Student::getChemistryScore() {
    return chemistryScore;
}

double Student::getAverageScore()const {
    return averageScore;
}

string Student::getAcademicPerformance()const {
    return academicPerformance;
}

string Student::calculateAcademicPerformance()const{
    if (averageScore >= 8.0)
        return "Giỏi";
    else if (averageScore >= 6.5)
        return "Khá";
    else if (averageScore >= 5.0)
        return "Trung bình";
    else
        return "Yếu";
}

void StudentManager::addStudent(){
    string name, gender;
    int age;
    double mathScore, physicsScore, chemistryScore;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter student gender: ";
    cin >> gender;

    cout << "Enter student age: ";
    cin >> age;

    cout << "Enter math score: ";
    cin >> mathScore;

    cout << "Enter physics score: ";
    cin >> physicsScore;

    cout << "Enter chemistry score: ";
    cin >> chemistryScore;

    Student student;

    students.push_back(student);

    cout << "Added student with ID: " << student.getID() << endl;
}

void StudentManager::updateStudent(int id) {
    for (auto& student : students) {
        if (student.getID() == id) {
            string name, gender;
            int age;
            double mathScore, physicsScore, chemistryScore;

            cout << "Enter new student name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter new student gender: ";
            cin >> gender;

            cout << "Enter new student age: ";
            cin >> age;

            cout << "Enter new math score: ";
            cin >> mathScore;

            cout << "Enter new physics score: ";
            cin >> physicsScore;

            cout << "Enter new chemistry score: ";
            cin >> chemistryScore;

            cout << "Updated student with ID: " << id << endl;

            Student student;

            break;
        }else{
        cout << "No student found with ID: " << id << endl;
    }
}
}

 
void StudentManager::removeStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getID() == id) {
            students.erase(it);
            cout << "Removed student with ID: " << id << endl;
            return;
        }
    }
    cout << "No student found with ID: " << id << endl;
}

void StudentManager::searchStudentsByName(const string& name){
     vector<Student> foundStudents;

        for (const auto& student : students) {
            if (student.getName() == name) {
                foundStudents.push_back(student);
            }
        }

        if (!foundStudents.empty()) {
            cout << "Students found with name: " << name << endl;
            for (const auto& student : foundStudents) {
                cout << "ID: " << student.getID() << ", Name: " << student.getName() << ", Gender: " << student.getGender()
                     << ", Age: " << student.getAge() << ", Average Score: " << student.getAverageScore()
                     << ", Academic Performance: " << student.getAcademicPerformance() << endl;
            }
        } else {
            cout << "No students found with name: " << name << endl;
        }
    
}

void StudentManager::sortStudentsByAverageScore() {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].getAverageScore() < students[minIndex].getAverageScore()) {
                minIndex = j;
            }
        }

        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
    
    cout << "Sorted students by average score." << endl;
}


void StudentManager::sortStudentsByName() {
    int n = students.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].getName() < students[minIndex].getName()) {
                minIndex = j;
            }
        }

        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
    
    cout << "Sorted students by name." << endl;
}


void StudentManager::displayStudents() {
        cout << "Student List:" << endl;
        for (const auto& student : students ) {
             cout << "ID:, Name: " << student.getName() << ", Gender: " << student.getGender()
                << ", Age: " << student.getAge() << ", Average Score: " << student.getAverageScore()
                << ", Academic Performance: " << student.getAcademicPerformance() << endl;
        }
}