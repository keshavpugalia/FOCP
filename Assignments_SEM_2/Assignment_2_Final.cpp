// ASSIGNMENT-2 FOCP-II 

/*We Have to Design a University Management System using C++ by implementing classes
like Person, Student, Professor, and others, focusing on encapsulation and polymorphism
Demonstrate OOP principles through object creation, secure data handling, and polymorphic 
method calls using a test program.*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person() {}
    Person(string n, int a, string id, string c) {
        name = n;
        age = a;
        ID = id;
        contact = c;
    }
    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << ", Contact: " << contact << endl;
    }
    double calculatePayment() {
        return 0.0;
    }
};

// Student Class
class Student : public Person {
public:
    string enrollmentDate;
    string program;
    float GPA;
    Student(string n, int a, string id, string c, string ed, string p, float g)
        : Person(n, a, id, c) {
        enrollmentDate = ed;
        program = p;
        GPA = g;
    }
    void displayDetails() {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << ", Enrollment Date: " << enrollmentDate << endl;
    }
    double calculatePayment() {
        return 1000.0;
    }
};

// Professor Class
class Professor : public Person {
public:
    string department;
    string specialization;
    string hireDate;
    Professor(string n, int a, string id, string c, string d, string s, string h)
        : Person(n, a, id, c) {
        department = d;
        specialization = s;
        hireDate = h;
    }
    void displayDetails() {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }
    double calculatePayment() {
        return 5000.0;
    }
};

// Course Class
class Course {
public:
    string code;
    string title;
    int credits;
    string description;
    Course(string c, string t, int cr, string d) {
        code = c;
        title = t;
        credits = cr;
        description = d;
    }
    void display() {
        cout << "Course Code: " << code << ", Title: " << title << ", Credits: " << credits << endl;
    }
};

// Department Class
class Department {
public:
    string name;
    string location;
    float budget;
    Department(string n, string l, float b) {
        name = n;
        location = l;
        budget = b;
    }
    void display() {
        cout << "Department: " << name << ", Location: " << location << ", Budget: " << budget << endl;
    }
};

// GradeBook Class
class GradeBook {
public:
    map<string, float> grades;
    void addGrade(string studentID, float grade) {
        grades[studentID] = grade;
    }
    float calculateAverageGrade() {
        float sum = 0;
        for (auto x : grades) {
            sum += x.second;
        }
        if (grades.size() == 0) return 0.0;
        return sum / grades.size();
    }
    float getHighestGrade() {
        float max = 0;
        for (auto x : grades) {
            if (x.second > max) {
                max = x.second;
            }
        }
        return max;
    }
};

// EnrollmentManager Class
class EnrollmentManager {
public:
    map<string, vector<string>> enrollment;
    void enrollStudent(string courseCode, string studentID) {
        enrollment[courseCode].push_back(studentID);
    }

    int getEnrollmentCount(string courseCode) {
        return enrollment[courseCode].size();
    }
};

// Main function
int main() {
    // Creating students
    Student s1("Rohan", 20, "S101", "1234567890", "2023-01-01", "CS", 3.8);
    Student s2("Riya", 22, "S102", "0987654321", "2023-01-01", "IT", 3.5);

    // Creating professors
    Professor p1("Prof. Manoj Kumar", 45, "P201", "555-1234", "CS", "AI", "2010-08-01");
    Professor p2("Prof. Ramesh Gupta", 50, "P202", "555-5678", "Math", "Statistics", "2008-09-01");

    // Creating course and department
    Course c1("CS101", "Intro to C++", 3, "Learn basics of C++ programming");
    Department d1("Computer Science", "Block A", 1000000);

    // Displaying all details
    cout << "\n--- Student Details ---\n"<<endl;
    s1.displayDetails();
    cout << "Payment: INR " << s1.calculatePayment() << endl<<endl;

    s2.displayDetails();
    cout << "Payment: INR " << s2.calculatePayment() << endl<<endl;

    cout << "\n--- Prof. Details ---\n"<<endl;

    p1.displayDetails();
    cout << "Payment: INR " << p1.calculatePayment() << endl<<endl;

    p2.displayDetails();
    cout << "Payment: INR " << p2.calculatePayment() << endl<<endl;

    // GradeBook
    GradeBook gb;
    gb.addGrade("S101", 85);
    gb.addGrade("S102", 90);
    cout << "\nAverage Grade: " << gb.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gb.getHighestGrade() << endl;

    // Enrollment
    EnrollmentManager em;
    em.enrollStudent("CS101", "S101");
    em.enrollStudent("CS101", "S102");
    cout << "Enrollment in CS101: " << em.getEnrollmentCount("CS101") << endl;

    return 0;
}