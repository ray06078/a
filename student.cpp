#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;
    static int studentCount;

public:
    // Parameterized constructor
    Student(string studentName, int roll, double studentMarks)
        : name(studentName), rollNumber(roll), marks(studentMarks) {
        ++studentCount;
    }

    // Destructor updates the number of active Student objects
    ~Student() { --studentCount; }

    // Function overloading: two methods with the same name
    void display() const {
        cout << "Roll: " << rollNumber << " | Name: " << name
             << " | Marks: " << fixed << setprecision(1) << marks << '\n';
    }

    void display(bool showGrade) const {
        display();
        if (showGrade) {
            char grade = marks >= 90 ? 'A' : marks >= 75 ? 'B' :
                         marks >= 60 ? 'C' : marks >= 40 ? 'D' : 'F';
            cout << "Grade: " << grade << '\n';
        }
    }

    static int getStudentCount() { return studentCount; }

    // Friend function can read private data from both objects
    friend void showHigherScorer(const Student& a, const Student& b);

    // Overloaded > operator compares marks
    bool operator>(const Student& other) const {
        return marks > other.marks;
    }
};

int Student::studentCount = 0;

void showHigherScorer(const Student& a, const Student& b) {
    if (a.marks > b.marks)
        cout << "Higher scorer: " << a.name << " (" << a.marks << ")\n";
    else if (b.marks > a.marks)
        cout << "Higher scorer: " << b.name << " (" << b.marks << ")\n";
    else
        cout << "Both students have equal marks.\n";
}

int main() {
    cout << "=== STUDENT MARKS COMPARISON SYSTEM ===\n\n";
    Student student1("Aisha", 101, 87.5);
    Student student2("Rahul", 102, 92.0);

    cout << "Student 1 (display without grade):\n";
    student1.display();
    cout << "\nStudent 2 (overloaded display with grade):\n";
    student2.display(true);

    cout << "\nActive student objects: " << Student::getStudentCount() << '\n';
    cout << "\nFriend function result:\n";
    showHigherScorer(student1, student2);

    cout << "\nOverloaded > operator result:\n";
    if (student1 > student2)
        cout << "Student 1 has higher marks.\n";
    else if (student2 > student1)
        cout << "Student 2 has higher marks.\n";
    else
        cout << "Both students have equal marks.\n";

    cout << "\nProgram executed successfully.\n";
    return 0;
}
