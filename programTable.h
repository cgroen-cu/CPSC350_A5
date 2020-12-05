#include "BST.h"
#include "Faculty.h"
#include <fstream>  //File IOS
#include <string>

class programTable {
public:
  programTable();
  ~programTable();

  //PRGORAM METHODS
  void printStudentTree();
  void printFacultyTree();
  void printStudent(int id);
  void printFaculty(int id);
  void printAdvisor(int id);  //intakes student ID pritns their advisors info
  void printAdvisees(int id);
  void addStudent(Student s);
  void addStudent(int id, string n, string l, string m, double g, int a);  //overload for user input
  void deleteStudent(int id); //CHANGE ADVISEE LIST
  void addFaculty(Faculty f);
  void addFaculty(int id, string n, string l, string d);  //overload for user input
  void deleteFaculty(int id); //CHANGE ADVISORS
  void addAdvisee(int facID, int studentID); //adds a student to a Faculty advisees list
  void addAdvisee(int studentID);
  void removeAdvisee(int facID, int studentID); //CHANGES ADVISEES
  void printNoAdvisors();
  void rollBack(int x); //takes in number of steps to roll back;
  void exitProgram();


  //extra methods
  void runProgram();
  void promptInput();
  void setUp();
  void backUp();  //when structure is changed - copy old  tree to stack

private:
  //student BST
  BST<Student> *studentTree;
  //Faculty BST
  BST<Faculty> *facultyTree;
  char continu;
  string entry;
  int intEntry;

};
