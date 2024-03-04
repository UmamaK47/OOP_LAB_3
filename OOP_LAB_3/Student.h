#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student
{
    private:
        string name;
        vector<char> grades;
    public:
        Student(string n) : name(n) {}
        void addGrade(char grade) {
                grades.push_back(grade);   
        }
        void displayInfo() {
            cout << "Student: " << name << ", Grades: ";
            for (char grade : grades) {
                grade = toupper(grade);
                cout << grade << " ";
            }
        }
        string getName() {
            return name;
        }
};

