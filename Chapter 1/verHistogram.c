#include <stdio.h>

#define   IN        1     /* inside a word */
#define   OUT       0     /* outside a word */
#define   MAXWORD   11
#define   MAXHIST   15

/* print vertical histogram */
int main() {
  int c, i, j, nc, state;
  int len;                /* length of each bar */
  int maxvalue;           /* maximum value for wl[] */  
  int ovflow;             /* number of overflow words */
  int wl[MAXWORD];        /* word length counters */

  state = OUT;
  nc = 0;                 /* number of chars in a word */
  ovflow = 0;             /* number of words >= MAXWORD */
  for (i = 0; i < MAXWORD; i++) {
    wl[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
      if (nc < MAXWORD) {
        wl[nc]++;
      }
      else {
        ovflow++;
      }
      nc = 0;
    } else if (state == OUT) {
      state = IN;
      nc = 1;             /* beginning of a new word */
    } else {
      nc++;               /* inside a word */
    }
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; i++) {
    if (wl[i] > maxvalue) {
      maxvalue = wl[i];
    }
  }

  for (i = MAXHIST; i > 0; i--) {
    for (j = 1; j < MAXWORD; j++) {
      if (wl[j] * MAXHIST / maxvalue >= i) {
        printf("%5c", '*');
      } else {
        printf("%5c", ' ');
      }
    }
    putchar('\n');
  }

  for (i = 1; i < MAXWORD; i++) {
    printf("%4d ", i);
  }
  printf("\n");
  for (i = 1; i < MAXWORD; i++) {
    printf("%4d ", wl[i]);
  }
  printf("\n");
  if (ovflow > 0) {
    printf("There are %d words >= %d", ovflow, MAXWORD);
  }
}