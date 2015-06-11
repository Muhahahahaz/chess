#include <stdio.h>
#include <stdlib.h>

void check(long i) {
  if(i == 1)
    return;

  long x = i;

  while(1) {
    if(i % 2 == 0)
      i /= 2;
    else
      i = (3*i + 1) / 2;

    if(i < x)
      return;
  }
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    fprintf(stderr, "Error! Usage: serial <START> <STOP>\n");
    return -1;
  }

  long i = atol(argv[1]), max = atol(argv[2]);

  for( ; i <= max; i++) {
    check(i);
  }

  printf("Success! All i <= %ld checked out.\n", max);

  return 0;
}
