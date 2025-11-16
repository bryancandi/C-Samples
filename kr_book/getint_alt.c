/* Sample 5.2 - simplified alternate version
 * getint: get next integer from input into *pn
 * modified to not use getch and ungetch
 */

#include <ctype.h>
#include <stdio.h>

int getint(int *pn);

int main(void)
{
    int n;

    if (getint(&n) != 0)
    {
        printf("%d\n", n);
    }
    else
    {
        printf("Not a number\n");
    }

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getchar())) // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar();
    }
    for (*pn = 0; isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    return c;
}
