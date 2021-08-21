#include <stdio.h>

#define   IN        1     /* inside a word */
#define   OUT       0     /* outside a word */
#define   MAXWORD   11
#define   MAXHIST   15

/* print horizontal histogram */
int main() {
  int c, i, nc, state;
  int len;                /* length of each bar */
  int maxvalue;           /* maximum value for wl[] */  
  int ovflow;             /* number of overflow words */
  int wl[MAXWORD];        /* word length counters */

  state = OUT;
  nc = 0;
  ovflow = 0;
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

  for (i = 1; i < MAXWORD; i++) {
    printf("%5d - %5d : ", i, wl[i]);
    if (wl[i] > 0) {
      if ((len = (wl[i] * MAXHIST) / maxvalue) <= 0) {
        len = 1;
      }
    }
    else {
      len = 0;
    }
    while (len > 0) {
      putchar('*');
      len--;
    }
    putchar('\n');    
  }

  if (ovflow > 0) {
    printf("There are %d words >= %d", ovflow, MAXWORD);
  }
}