#include <stdio.h>

int main() {
  int c;
  int blank, tab, newline;

  blank = 0;
  tab = 0;
  newline = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {        
      blank++;                 
    } else if (c == '\t') {
      tab++;
    } else if (c == '\n') {
      newline++;
    }
  }
  printf("====================\n");
  printf("%7s: %d\n", "Blank", blank);
  printf("%7s: %d\n", "Tab", tab);
  printf("%7s: %d\n", "Newline", newline);
}