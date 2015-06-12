#include <iostream>
#include "bitboard.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  /*if(argc != 3) {
    fprintf(stderr, "Error! Usage: serial <START> <STOP>\n");
    return -1;
  }*/

  Board b;

  cout << "HELLO!" << endl;

  b.print();

  /*long i = atol(argv[1]), max = atol(argv[2]);

  for( ; i <= max; i++) {
    check(i);
  }

  printf("Success! All i <= %ld checked out.\n", max);*/

  return 0;
}
