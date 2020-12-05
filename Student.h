//Student.h
//header file for student.h
using namespace std;
#include <iostream>

class Student{
  public:
    //constructors
    Student();
    Student(int id, string n, string l, string m, double g, int a);
    ~Student();
    string print(); //prints all student info
    int getID(); //return student ID
    int getAdvisor(); //returns facutly advisor ID
    void changeAdvisor(int id); //changes advisor ID

    bool operator==(const Student &s);
    bool operator!=(const Student &s);
    bool operator<(const Student &s);
    bool operator<=(const Student &s);
    bool operator>(const Student &s);
    bool operator>=(const Student &s);

  private:
    int studentID;
    string Name;
    string level;
    string major;
    double gpa;
    int advisor;
};
