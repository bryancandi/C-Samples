/* Sample 5.12
 * undcl: convert word descriptions to declaration
 * example: x is a function returning a pointer to an array of pointers to functions returning char
 * can be expressed as: x () * [] * () char
 * which returns: char (*(*x())[])()
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100        // maximum tokens
#define BUFSIZE 100         // buffer size for getch/ungetch

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;              // type of last token
char token[MAXTOKEN];       // last token string
char out[1000];             // output string

int getch(void);
void ungetch(int c);
char buf[BUFSIZE];          // buffer for ungetch
int bufp = 0;               // next free position in buf

// convert word descriptions to declaration
int main(void)
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n' && type != ';')
        {
            if (type == PARENS || type == BRACKETS)
            {
                strcat(out, token);
            }
            else if (type == '*')
            {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

// gettoken: return next token
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '\n')
    {
        return tokentype = '\n';
    }
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
        {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
}

// getch: get a (possibly pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push character back on input
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
