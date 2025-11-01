/* Exercise 1-24 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); // open file in read mode
    if (file == NULL)
    {
        printf("%s: Cannot access file '%s'\n", argv[0], argv[1]);
        return 2;
    }

    char c;
    int parens = 0;

    // read the file one char at a time and check for balance
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '(')
        {
            parens++;
        }
        if (c == ')')
        {
            parens--;
        }
    }

    if (parens == 0)
    {
        printf("Parentheses () are balanced.\n");
    }
    else
    {
        printf("Parentheses () are unbalanced.\n");
    }
    // TO-DO: add other syntax and balance checks
    // also add line number tracking to report where the error is
    
    fclose(file);

    return 0;
}
