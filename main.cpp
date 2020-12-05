#include "programTable.h"

int main(int argc, char** argv){

  programTable *p1 = new programTable();
  p1->setUp();
  p1->promptInput();
  cout << "END" << endl;
}
