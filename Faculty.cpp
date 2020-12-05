#include "Faculty.h"

Faculty::Faculty(){}

Faculty::Faculty(int id, string n, string l, string d){
  facultyID = id;
  Name = n;
  level = l;
  department = d;
  //initate advisee list
  adviseeNum = 0;
  listAdvisees = new DoublyLinkedList<int>;
}

Faculty::~Faculty(){}

string Faculty::print(){
  string output;
  output += Name + "\n";
  output += "ID: " + to_string(facultyID);
  output +="\nLevel: " + level;
  output += "\nDepartment: " + department;
  output += "\n"+ to_string(listAdvisees->getSize())+" Advisees:";
  for (int i = 0; i < listAdvisees->getSize(); i++){
    output += "\n" + to_string(listAdvisees->returnPos(i));
  }
  //iterate through and print out advisees
  return output;
}

int Faculty::getID(){
  return facultyID;
}

void Faculty::printAllAdvisees(){
  cout << "Printing List of Advisees" << endl;
  //loop through list
  if (listAdvisees->isEmpty()){
    cout << "No Advisees listed." << endl;
  } else {
    for (int i = 0; i < listAdvisees->getSize(); i++){
      //cout << "student " << i << endl;
      cout << listAdvisees->returnPos(i) << endl;
    }
  }
}

void Faculty::addAdvisee(int studentID){
  adviseeNum++;
  listAdvisees->insertBack(studentID);
}

void Faculty::removeAdvisee(int id){
  int x = 0;
  //search for id
  for (int i = 0; i < listAdvisees->getSize(); i++){
    if (listAdvisees->returnPos(i) == id){
      cout << "found and removing student" << endl;
      listAdvisees->deletePos(i);
      adviseeNum--;
      x++;
    }
  }
  if (x < 1){
    cout << "Error, student not found" << endl;
    //if found remove - if not found - error
  }
}

void Faculty::removeAllAdvisees(){
  adviseeNum = 0;
  //remove all
  while (!listAdvisees->isEmpty()){
    listAdvisees->removeFront();
  }
  cout << "All Advisees removed" << endl;
}

int Faculty::getAdviseeSize(){
  return listAdvisees->getSize();
}

int Faculty::getAdvisee(int p){
  //cout << "GETTING ADVISEE " << endl;
  return listAdvisees->returnPos(p);
}

//comparison operators

bool Faculty::operator==(const Faculty &s){
  if (facultyID = s.facultyID){
    return true;
  } else {
    return false;
  }
}
bool Faculty::operator!=(const Faculty &s){
  if (facultyID = s.facultyID){
    return false;
  } else {
    return true;
  }
}
bool Faculty::operator<(const Faculty &s){
  if (facultyID < s.facultyID){
    return true;
  } else {
    return false;
  }
}
bool Faculty::operator<=(const Faculty &s){
  if (facultyID <= s.facultyID){
    return true;
  } else {
    return false;
  }
}
bool Faculty::operator>(const Faculty &s){
  if (facultyID > s.facultyID){
    return true;
  } else {
    return false;
  }
}
bool Faculty::operator>=(const Faculty &s){
  if (facultyID >= s.facultyID){
    return true;
  } else {
    return false;
  }
}
