#include "programTable.h"

programTable::programTable(){
    studentTree = new BST<Student>;
    facultyTree = new BST<Faculty>;
    continu = 'Y';
    entry = "";
    intEntry = 0;
}

programTable::~programTable(){}

//Program Methods
void programTable::printStudentTree(){
  cout << studentTree->printTree() << endl;
}
void programTable::printFacultyTree(){
  cout << facultyTree->printTree() << endl;
}
void programTable::printStudent(int id){
  //search for node - ifthere then retrive, if not get new id
  cout << "Printing Student: " << id << endl;
  continu = 'Y';
  intEntry = id;
  //to caps
  while (continu == 'Y'){
    if (studentTree->searchNode(intEntry)){
      //found student
      cout << studentTree->retrieveNode(intEntry).print() << endl;
      break;
    } else{
      cout << "Could not find a student with that ID. Would you like to try again? (Y/N)" << endl;
      cin >> continu;
      cout << "Enter ID: ";
      cin >> intEntry;

    }
  }
}
void programTable::printFaculty(int id){
  //search for node - ifthere then retrive, if not get new id
  continu = 'Y';
  intEntry = id;
  //to caps
  while (continu == 'Y' || continu == 'y'){
    if (facultyTree->searchNode(intEntry)){
      cout << facultyTree->retrieveNode(intEntry).print() << endl;
      break;
    } else{
      cout << "Could not find a faculty with that ID. Would you like to try again? (Y/N)" << endl;
      cin >> continu;
      cout << "Enter ID: ";
      cin >> intEntry;

    }
  }
}

void programTable::printAdvisor(int id){
  //search for node - if there then retrive, if not get new id
  cout << "Printing Advisor..." << endl;
  continu = 'Y';
  intEntry = id;
  int advisorID = 0;
  //to caps
  while (continu == 'Y'){
    if (studentTree->searchNode(intEntry)){
      advisorID = studentTree->retrieveNode(intEntry).getAdvisor();
      //Then check if advisor exists
      if (facultyTree->searchNode(advisorID)){
        //cout << "Found Advisor" << endl;
        cout << facultyTree->retrieveNode(advisorID).print() << endl;
      } else {
        //advisor doesnt exist
        cout << "ERROR: The ID is not a valid Faculty member's ID."<< endl;
      }
      continu = 'N';
    } else{
      //student doesnt exist
      cout << "Could not find a student with that ID. Would you like to try again? (Y/N)" << endl;
      cin >> continu;
      cout << "Enter ID: ";
      cin >> intEntry;

    }
  }
}

//NEEDS FIXING
void programTable::printAdvisees(int id){
  //search for node - if there then retrive, if not get new id
  cout << "Printing Advisees" << endl;
  continu = 'Y';
  intEntry = id;
  int advisorID = 0;
  //to caps

  while (continu == 'Y'|| continu == 'y'){
    //Find faculty
    if (facultyTree->searchNode(intEntry)){
      //cout<< "Found Faculty" << endl;
      //for loop through advisee list
      //retrieve advisee ids
      //then print ids
      //cout << facultyTree->retrieveNode(intEntry).getAdviseeSize() << endl;
      //facultyTree->retrieveNode(intEntry).printAllAdvisees();
      //facultyTree->retrieveNode(intEntry).printAllAdvisees(); //these work
      int x = facultyTree->retrieveNode(intEntry).getAdviseeSize();
      //cout << x << endl;
      //cout << facultyTree->retrieveNode(intEntry).getAdvisee(0);
      //cout << facultyTree->retrieveNode(intEntry).getAdvisee(1);
      Faculty f = facultyTree->retrieveNode(intEntry);
      //printStudent(123);
      //printStudent(122);
      for (int i = 0; i < x; i++){
        //cout << i << endl;
        //cout << "ID: " << f.getAdvisee(i) << endl; //Segfault here
        printStudent(f.getAdvisee(i));
        //cout << "FINISHED" << endl;
      }
      //Finished and break
      //cout << "Finished" << endl;
      //delete f;
      break;
    } else{
      //student doesnt exist
      cout << "Could not find a faculty with that ID. Would you like to try again? (Y/N)" << endl;
      cin >> continu;
      cout << "Enter ID: ";
      cin >> intEntry;
    }
  }
}

void programTable::addStudent(Student s){
  studentTree->insertNode(s);
  //now add student to advisors list
  int advisorID = s.getAdvisor();
  this->addAdvisee(advisorID, s.getID());

  cout << "Student Added Successfully" << endl;
}
void programTable::addStudent(int id, string n, string l, string m, double g, int a){
  Student s(id, n, l, m, g, a);
  studentTree->insertNode(s);
  //cout << "Student Added Successfully" << endl;
}
void programTable::deleteStudent(int id){
  //Retrieve Advisor's ID
  //remove the mfrom advisors advisee list
  //remove student
  //Check if student exists
  if (studentTree->searchNode(id)){
    cout << "Removing Student..." << endl;
    //remove them from advisee list
    studentTree->removeNode(studentTree->retrieveNode(id));
  } else cout << "Student does not exist" << endl;

}

void programTable::addFaculty(Faculty f){
  facultyTree->insertNode(f);
  cout << "Faculty Member Added Successfully" << endl;
}
void programTable::addFaculty(int id, string n, string l, string d){
  Faculty f (id, n, l, d);
  facultyTree->insertNode(f);
  cout << "Faculty Member Added Successfully" << endl;
}
void programTable::deleteFaculty(int id){
  //cout << "Deleting Faculty" << endl;
  continu = 'Y';
  intEntry = id;
  int advisorID = 0;
  //to caps

  while (continu == 'Y'|| continu == 'y'){
    //Check if faculty Exists
    if (facultyTree->searchNode(intEntry)){
      //retrieve advisees ids
      //remove the deleted faculty member from their advisors
      int x = facultyTree->retrieveNode(intEntry).getAdviseeSize();
      for (int i = 0; i < x; i++){
        this->addAdvisee(facultyTree->retrieveNode(intEntry).getAdvisee(i));
      }

      //remove faculty
      facultyTree->removeNode(facultyTree->retrieveNode(intEntry));
      break;
    } else{
      cout << "Could not find a faculty with that ID. Would you like to try again? (Y/N)" << endl;
      cin >> continu;
      cout << "Enter ID: ";
      cin >> intEntry;
    }

  }

}




void programTable::addAdvisee(int id, int studentID){
  cout << "Adding advisee" << endl;{}
  //change students advisor to facID
  //find fac
  //add student to their advisr
  //studentTree->retrieveNode(studentID).print();
  //facultyTree->retrieveNode(id).print();
  if (facultyTree->isEmpty()){
      //if tree is empty
    cout << "No Faculty listed. Student does not have a registered advisor." << endl;
  } else {
    //If not empty

    if (facultyTree->searchNode(id)){
      cout << "found faculty" << endl;
      //found faculty
      facultyTree->retrieveNode(id).addAdvisee(studentID);
      //change students advisor to new advisor ID
      studentTree->retrieveNode(studentID).changeAdvisor(id);
    } else{
      //Could not find faculty
      cout << "Could not find a faculty with that ID. Student Does not have an adivsor" << endl;
    }
  }
}
//Used to cjhanged student advisor to 0
void programTable::addAdvisee(int studentID){
  cout << "Removing Student's Advisor..." << endl;{}
  studentTree->retrieveNode(studentID).changeAdvisor(00);
  studentTree->retrieveNode(studentID).print();
}
void programTable::removeAdvisee(int facID, int studentID){
  if (facultyTree->searchNode(facID)){
    //found faculty
    facultyTree->retrieveNode(facID).removeAdvisee(studentID);
    //needs to cahnge students advisor

  } else{
    //Could not find faculty
    cout << "Could not find a faculty with that ID. Student does not have an advisor." << endl;
  }
}


void programTable::promptInput(){
  int x = 0;
  string name;
  int id = 0;
  string level;
  string major;
  string department;
  int advisor;
  double gpa;
  //char continu = 'Y';
  int advisorID;
  while (x == 0){
    cout << "1.Print all students and their information (sorted by ascending id #)\n2.Print all faculty and their information (sorted by ascending id #)\n3.Find and display student information given the students id\n4.Find and display faculty information given the faculty id\n5.Given a student’s id, print the name and info of their faculty advisor\n6.Given a faculty id, print ALL the names and info of his/her advisees.\n7.Add a new student\n8.Delete a student given the id\n9.Add a new faculty member\n10.Delete a faculty member given the id.\n11.Change a student’s advisor given the student id and the new faculty id.\n12.Remove an advisee from a faculty member given the ids\n13.Rollback\n14.Exit" << endl;
    cin >> intEntry;
    if (intEntry == 1){
      //print all students
      cout << "Printing all students..." << endl;
      printStudentTree();
    } else if (intEntry == 2){
      //print all faculty
      cout << "Printing all faculty members..." << endl;
      printFacultyTree();
    } else if (intEntry == 3){
      //find student
      //prompt for id
      cout << "Enter Student ID: " << endl;
      cin >> intEntry;
      printStudent(intEntry);
    } else if (intEntry == 4){
      //find faculty
      //prompt for id
      cout << "Enter Faculty ID: " << endl;
      cin >> intEntry;
      printFaculty(intEntry);
    }else if (intEntry == 5){
      //find advisr
      //prompt for student id
      cout << "Enter Student ID: " << endl;
      cin >> intEntry;
      printAdvisor(intEntry);
    }else if (intEntry == 6){
      //find advisee
      //prompt for faculty id
      cout << "Enter Faculty ID: " << endl;
      cin >> intEntry;
      printAdvisees(intEntry);
    }else if (intEntry == 7){
      //add student
      //prompt for name,id,level,major,gpa,advisorID
      cout << "Enter Student ID: ";
      cin >> id;
      cout << "Enter Name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter Major: ";
      cin >> major;
      cout << "Enter GPA: ";
      cin >> gpa;
      cout << "Enter Advisor ID: ";
      cin >> advisorID;
      addStudent(id,name,level,major,gpa,advisorID);
      cout << "Student Added Successfully" << endl;
    }else if (intEntry == 8){
      //delete student
      //prompt for id
      cout << "Enter Student ID: " << endl;
      cin >> intEntry;
      deleteStudent(intEntry);
    }else if (intEntry == 9){
      //Add faculty
      //prompt for name,id,level,department,
      cout << "Enter Faculty ID: ";
      cin >> id;
      cout << "Enter Name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter Department: ";
      cin >> department;
      addFaculty(id,name,level,department);
    }else if (intEntry == 10){
      //delete faculty
      //prompt for id
      cout << "Enter Faculty ID: " << endl;
      cin >> intEntry;
      deleteFaculty(intEntry);
    }else if (intEntry == 11){
      //Change advisor
      //prompt for student id and new advisor id
      continu = 'Y';
      while (continu == 'Y' || continu == 'y'){
        cout << "Enter student ID: ";
        cin >> intEntry;
        if (!studentTree->searchNode(intEntry)){
          cout << "A student does not exist with that id. Try again? (Y/N): ";
          cin >> continu;
        } else {
          break;
        }
      }
      while (continu == 'Y' || continu == 'y'){
        cout << "Enter new advisor ID: ";
        cin >> id;

        if (!studentTree->searchNode(intEntry)){
          cout << "A student does not exist with that id. Try again? (Y/N): ";
          cin >> continu;
        } else {
          addAdvisee(id, intEntry);
          break;
        }
      }
    }else if (intEntry == 12){
      //Remove Advisee
      //prompt for advisr id and advisee id to be removed
      cout << "Enter Faculty Advisor ID: ";
      cin >> intEntry;
      cout << "Enter Advisee ID to be removed: ";
      cin >> id;
      //execute
      removeAdvisee(intEntry, id);
      //Prompt if they want to add a new advisor to the student
      //print faculty
      cout << "The student will not have an adivsor. Would you like to add give them an advisor?:(Y/N) ";
      cin >> continu;
      if (continu == 'Y' || continu == 'y'){
        cout << "Here is the current faculty" << endl;
        printFacultyTree();
        cout << "Enter new advisor ID: ";
        cin >> intEntry;
        addAdvisee(intEntry, id);
      } else {
        cout << "Student will not have an advisor." << endl;
      }

    }else if (intEntry == 13){
      //Rollback
      //prompt rollback 1-5
    }else if (intEntry == 14){
      //Exit
      exitProgram();
      break;
      x++;
    }
  }

}

void programTable::exitProgram(){
  cout << "Saving Files..." << endl;
  int x = 0;
  ofstream myfile;
  //Open and print to faculty file
  myfile.open("facultyTable.txt");
  if (myfile.is_open())
  {
    myfile << facultyTree->printTree();
    myfile.close();
    cout << "Saved Faculty" << endl;
  }
  else cout << "Unable to open file";
  myfile.open("studentTable.txt");
  if (myfile.is_open())
  {
    myfile << studentTree->printTree();
    myfile.close();
    cout << "Saved Students" << endl;
  }
  else cout << "Unable to open file";
  cout << "Exiting program..." << endl;
}

void programTable::setUp(){
  //Basic Variables
  int x = 0;
  int lineNum = 0;
  int newHold = 0;
  string line;
  ifstream myfile;
  //Variables for creating objects
  string name;
  int id = 0;
  string level;
  string major;
  string department;
  int advisor;
  double gpa;
  int advisorID;


  myfile.open("facultyTable.txt");
  if (myfile.is_open())
  {
    //read from file and create faculty then add them to faculty tree
    while (getline(myfile, line)){
      lineNum++;
      //cout << "LineNum:"<<lineNum << endl;
      //cout << "Line: "<<line << endl;
      //cout<< "new hold:" <<newHold << endl;
      //Name of faculty
      if(newHold == 0){
        name = line;
        //cout << "NAME: " << name << endl;
        newHold++;
      }
      else if (newHold == 1){
        //ID Number
        id = stoi(line.substr(4,line.length()));
        //cout << "ID: " << id << endl;
        newHold++;
      } else if (newHold == 2){
        // level
        //cout << line.substr(7,line.length()) << endl;
        level = line.substr(7,line.length());
        //cout << "Level: " << level << endl;
        newHold++;
      } else if (newHold == 3){
        //Department
        department = line.substr(12,line.length());
        //cout << "Department: " << department << endl;
        Faculty f (id, name, level, department);
        addFaculty(f);
        newHold++;
      }
      else if (newHold == 4){
        //ADvisee list
        //Get number of advisees first
        x = line.find(' ');
        x = stoi(line.substr(0,x));
        //cout << "Number of Advisees: " << x << endl;
        if (x == 0){
          newHold = 0;
        } else {
          x = x+newHold;
          newHold++;
        }


      } else if (newHold < x){
        //cout << newHold << endl;
        newHold++;
      } else {
        newHold = 0;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  //Now for student File
  newHold = 0;
  myfile.open("studentTable.txt");
  if (myfile.is_open())
  {
    //read from file and create faculty then add them to faculty tree
    while (getline(myfile, line)){
      lineNum++;
      //cout << lineNum << endl;
      //Name of faculty
      if(newHold == 0){
        name = line;
        //cout << "NAME: " << name << endl;
        newHold++;
      }
      else if (newHold == 1){
        //ID Number
        id = stoi(line.substr(4,line.length()));
        //cout << "ID: " << id << endl;
        newHold++;
      } else if (newHold == 2){
        // level
        level = line.substr(7,line.length());
        //cout << "Level: " << level << endl;
        newHold++;
      } else if (newHold == 3){
        //major
        major = line.substr(7,line.length());
        //cout << "Major: " << major << endl;
        newHold++;
      }
      else if (newHold == 4){
        //GPA
        gpa = stod(line.substr(5,line.length()));
        //cout << "GPA: " << gpa << endl;
        newHold++;
      }else if (newHold == 5){
        //Advisor ID
        advisorID = stoi(line.substr(12,line.length()));
        //cout << "Advisor ID: " << advisorID << endl;
        Student s(id, name, level, major, gpa, advisorID);
        addStudent(s);
        newHold = 0;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file";
}
