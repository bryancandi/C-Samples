/* getch.c
 * getch: get a (possibly pushed back) character
 * ungetch: push character back on input
 */

#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100 // buffer size for getch/ungetch

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
