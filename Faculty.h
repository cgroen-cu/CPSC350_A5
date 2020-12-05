//Faculty.h
using namespace std;
#include <iostream>
#include "Student.h"
#include "DoublyLinkedList.h"

class Faculty{
  public:
    Faculty();
    Faculty(int id, string n, string l, string d);
    ~Faculty();
    string print(); //prints all student info
    int getID();
    void printAllAdvisees(); //prints all advisees
    void addAdvisee(int studentID);
    void removeAdvisee(int id); //removes advisee with ID
    void removeAllAdvisees(); //removes all adviesees
    int getAdviseeSize();
    int getAdvisee(int p);  //retrieves advisee ID number based off of position

    //Comparators
    bool operator==(const Faculty &s);
    bool operator!=(const Faculty &s);
    bool operator<(const Faculty &s);
    bool operator<=(const Faculty &s);
    bool operator>(const Faculty &s);
    bool operator>=(const Faculty &s);

  private:
    int facultyID;
    string Name;
    string level;
    string department;
    //List of advisees
    int adviseeNum;
    DoublyLinkedList<int> *listAdvisees;

};
