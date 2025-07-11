/*********************************************************
 * Simple Association:
 * Definition: "Association represents a using relationship 
 * between two classes."
 * 
 *   +---------+    uses    +---------+
 *   | Teacher |----------->| Student |
 *   +---------+            +---------+
 * 
 * Simple use: Teacher teaches Student.
 *********************************************************/

#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    Student(string n) : name(n) {}
};

class Teacher {
public:
    string name;
    Teacher(string n) : name(n) {}
    void teach(Student &s) {
        cout << name << " teaches " << s.name << endl;
    }
};
int main() {
    Teacher teacher("Mr. Smith");
    Student student("Alice");

    // Simple association: Teacher teaches Student
    teacher.teach(student);

    return 0;
}