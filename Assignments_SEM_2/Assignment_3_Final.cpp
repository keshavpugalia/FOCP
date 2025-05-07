//Assignment 3 FOCP - II

/*  What To Do?

    We Have Use inheritance to connect Student and Professor to the base Person class, 
    and create real-world relationships like a Course having a Professor, Department, 
    and enrolled Students.Implement association, aggregation, and composition to model 
    these relationships, then demonstrate them by creating and linking actual objects in main().
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Student inherits from Person
class Student : public Person {
    string studentID;
public:
    Student(string n, int a, string id) : Person(n, a) {
        studentID = id;
    }
    void display() {
        Person::display();
        cout << "Student ID: " << studentID << endl;
    }
};

// Professor inherits from Person
class Professor : public Person {
    string profID;
public:
    Professor(string n, int a, string id) : Person(n, a) {
        profID = id;
    }
    void display() {
        Person::display();
        cout << "Professor ID: " << profID << endl;
    }
};
class Department {
    string name;
public:
    Department(string n) {
        name = n;
    }
    void display() {
        cout << "Department: " << name << endl;
    }
};

// Course has relationships: taught by Professor, attended by Students, belongs to Department
class Course {
    string code;
    string title;
    Professor* teacher;
    Department* dept; 
    vector<Student*> students; 
public:
    Course(string c, string t, Professor* p, Department* d) {
        code = c;
        title = t;
        teacher = p;
        dept = d;
    }
    void addStudent(Student* s) {
        students.push_back(s);
    }
    void display() {
        cout << "\nCourse Code: " << code << ", Title: " << title << endl;
        teacher->display();
        dept->display();
        cout << "Enrolled Students:" << endl;
        for (Student* s : students) {
            s->display();
        }
    }
};

int main() {
    Department cs("Computer Science");
    Professor prof("Prof. Rajesh Sharma", 50, "P123");
    Student s1("Aman", 19, "S101");
    Student s2("Priya", 20, "S102");
    Course cpp("CS101", "C++ Programming", &prof, &cs);
    cpp.addStudent(&s1);
    cpp.addStudent(&s2);
    cpp.display();
    return 0;
}