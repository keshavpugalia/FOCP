//Assignment 4 FOCP-II

/*
We have to add exception handling and combine all components of the University Management System
into a single working program. It should gracefully handle errors (like invalid grades or full courses) 
and include a menu-driven interface for user interaction.
*/

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

class UniversitySystemException : public exception {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class Student {
    string name, id;
    float gpa;

public:
    Student(string n, string i, float g) {
        if (n.empty()) throw UniversitySystemException("Student name cannot be empty.");
        if (g < 0.0 || g > 4.0) throw GradeException("GPA must be between 0.0 and 4.0");
        name = n;
        id = i;
        gpa = g;
    }

    void show() {
        cout << "Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
    }

    string getId() { return id; }
};

class Course {
    string code;
    int capacity;
    vector<string> enrolledStudents;

public:
    Course(string c, int cap) : code(c), capacity(cap) {}

    void enroll(string studentID) {
        if (enrolledStudents.size() >= capacity)
            throw EnrollmentException("Course is full.");
        enrolledStudents.push_back(studentID);
    }

    void showEnrolled() {
        cout << "Course: " << code << " | Enrolled Students: ";
        for (string id : enrolledStudents) cout << id << " ";
        cout << endl;
    }

    string getCode() { return code; }
};

class GradeBook {
    map<string, float> grades;

public:
    void addGrade(string studentID, float grade) {
        if (grade < 0.0 || grade > 100.0)
            throw GradeException("Invalid grade entered.");
        grades[studentID] = grade;
    }

    float getAverage() {
        if (grades.empty()) return 0;
        float sum = 0;
        for (auto g : grades) sum += g.second;
        return sum / grades.size();
    }
};

class UniversitySystem {
    vector<Student> students;
    vector<Course> courses;
    GradeBook gradebook;
    ofstream logFile;

public:
    UniversitySystem() {
        logFile.open("error_log.txt", ios::app);
    }

    ~UniversitySystem() {
        logFile.close();
    }

    void logError(string msg) {
        logFile << "Error: " << msg << endl;
    }

    void addStudent(string name, string id, float gpa) {
        try {
            Student s(name, id, gpa);
            students.push_back(s);
            cout << "Student added.\n";
        } catch (exception& e) {
            cout << e.what() << endl;
            logError(e.what());
        }
    }

    void addCourse(string code, int cap) {
        courses.emplace_back(code, cap);
        cout << "Course added.\n";
    }

    void enrollStudentInCourse(string studentID, string courseCode) {
        try {
            for (Course& c : courses) {
                if (c.getCode() == courseCode) {
                    c.enroll(studentID);
                    cout << "Enrolled " << studentID << " in " << courseCode << endl;
                    return;
                }
            }
            throw EnrollmentException("Course not found.");
        } catch (exception& e) {
            cout << e.what() << endl;
            logError(e.what());
        }
    }

    void enterGrade(string studentID, float grade) {
        try {
            gradebook.addGrade(studentID, grade);
            cout << "Grade recorded.\n";
        } catch (exception& e) {
            cout << e.what() << endl;
            logError(e.what());
        }
    }

    void report() {
        cout << "---- University Report ----\n";
        cout << "Students:\n";
        for (Student& s : students) s.show();
        cout << "Courses:\n";
        for (Course& c : courses) c.showEnrolled();
        cout << "Average Grade: " << gradebook.getAverage() << endl;
    }
};

int main() {
    UniversitySystem system;
    int choice;

    while (true) {
        cout << "\n==== University System Menu ====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Course\n";
        cout << "3. Enroll Student in Course\n";
        cout << "4. Enter Grade\n";
        cout << "5. View Report\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        string name, id, code;
        float gpa, grade;
        int cap;

        switch (choice) {
            case 1:
                cout << "Enter Name, ID, GPA: ";
                cin >> name >> id >> gpa;
                system.addStudent(name, id, gpa);
                break;
            case 2:
                cout << "Enter Course Code and Capacity: ";
                cin >> code >> cap;
                system.addCourse(code, cap);
                break;
            case 3:
                cout << "Enter Student ID and Course Code: ";
                cin >> id >> code;
                system.enrollStudentInCourse(id, code);
                break;
            case 4:
                cout << "Enter Student ID and Grade: ";
                cin >> id >> grade;
                system.enterGrade(id, grade);
                break;
            case 5:
                system.report();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}