#include <stdio.h>

int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {        // '\n' is a character constant, whereas "\n" is a string constant
      nl++;                 // that happens to contain a single character */
    }
  }
  printf("%d\n", nl);
}