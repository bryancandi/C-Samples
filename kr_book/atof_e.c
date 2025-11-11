/* Exercise 4-2
 * atof: handle scientific notation
 */

#include <ctype.h>
#include <stdio.h>
#define BUFFER 1000

double my_atof(char s[]);

int main(void)
{
    int c;
    int i = 0;
    char s[BUFFER];

    while ((c = getchar()) != EOF && i < BUFFER - 1 && c != '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';

    printf("%.10f\n", my_atof(s));

    return 0;
}

double my_atof(char s[])
{
    double val, power;
    double factor = 1.0;
    int i, j, sign;
    int exp = 0;
    int exp_sign = 1;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    if (s[i] == '+' || s[i] == '-')
    {
        exp_sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (isdigit(s[i]))
    {
        exp = 10 * exp + (s[i] - '0');
        i++;
    }
    for (int j = 0; j < exp; j++)
    {
        factor *= 10.0;
    }
    if (exp_sign < 0)
    {
        factor = 1.0 / factor;
    }
    return (sign * val / power) * factor;
}
