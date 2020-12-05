//Student.cpp
//implementation for student class
#include "Student.h"

Student::Student(){}

Student::Student(int id, string n, string l, string m, double g, int a){
  studentID = id;
  Name = n;
  level = l;
  major = m;
  gpa = g;
  advisor = a;
}

Student::~Student(){}

string Student::print(){
  string output;
  output += Name + "\n";
  output += "ID: " + to_string(studentID);
  output +="\nLevel: " + level;
  output += "\nMajor: " + major;
  output += "\nGPA: " + to_string(gpa);
  output += "\nAdvisor ID: " + to_string(advisor);
  return output;
}

int Student::getID(){
  return studentID;
}

int Student::getAdvisor(){
  return advisor;
}

void Student::changeAdvisor(int id){
  advisor = id;
}

//comparison operators

bool Student::operator==(const Student &s){
  if (studentID = s.studentID){
    return true;
  } else {
    return false;
  }
}
bool Student::operator!=(const Student &s){
  if (studentID = s.studentID){
    return false;
  } else {
    return true;
  }
}
bool Student::operator<(const Student &s){
  if (studentID < s.studentID){
    return true;
  } else {
    return false;
  }
}
bool Student::operator<=(const Student &s){
  if (studentID <= s.studentID){
    return true;
  } else {
    return false;
  }
}
bool Student::operator>(const Student &s){
  if (studentID > s.studentID){
    return true;
  } else {
    return false;
  }
}
bool Student::operator>=(const Student &s){
  if (studentID >= s.studentID){
    return true;
  } else {
    return false;
  }
}
