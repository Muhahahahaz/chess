#include <iostream>
#include "position.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  Position p;

  p.print();
  cout << endl;
  p.printFEN();

  return 0;
}
