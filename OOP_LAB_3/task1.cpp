#include <iostream>
#include <vector>
#include <string>
#include"Student.h"
using namespace std;
int main() {
    vector<Student> students;
    while (true) {
        cout << "\n1. Add Student\n2. Add Grade\n3. Display Students\n4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter student name: ";
            cin >> name;
            students.push_back(Student(name));
            cout << "Student added successfully." << endl;
            break;
        }
        case 2: {
            if (students.empty()) {
                cout << "No students found. Please add a student first." << endl;
                break;
            }
            string name;
            cout << "Enter student name: ";
            cin >> name;
            for (Student& student : students) {
                if (student.getName() == name) {
                    char grade;
                    cout << "Enter grade: ";
                    cin >> grade;
                    if (grade >= 65 && grade <= 70 || grade >= 97 && grade<= 102){
                        student.addGrade(grade);
                        cout << "Grade added successfully." << endl;
                        break;
                    }
                    else {
                        cout << "Invalid grade";
                    }
                    
                }
                else{ cout << "Student not found." << endl; }
            }
            break;
        }
        case 3: {
            if (students.empty()) {
                cout << "No students found." << endl;
                break;
            }
            else{
                for (Student& student : students) {
                    student.displayInfo();
                }
            }
            
            break;
        }
        case 4: {
            cout << "Exiting program." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}