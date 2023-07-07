#ifndef __CLASSSINHVIEN_H
#define __CLASSSINHVIEN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    private:
        static int idCounter;///static int id = 001;ID = id;id++;
        int id;
        string name;
        string gender;
        int age;
        double mathScore;
        double physicsScore;
        double chemistryScore;
        double averageScore;
        string academicPerformance;
    public:
        Student();
        int getID()const;
        string getName()const;
        string getGender()const;
        int getAge()const;
        double getMathScore()const;
        double getPhysicsScore();
        double getChemistryScore();
        double getAverageScore()const;
        string getAcademicPerformance()const;
};

class StudentManager {
    private:
        vector<Student> students;
    public:
        void addStudent();
        void updateStudent(int id);
        void removeStudent(int id);
        void searchStudentsByName(const string& name);
        void sortStudentsByAverageScore();
        void sortStudentsByName();
        void displayStudents();
        
};

#endif