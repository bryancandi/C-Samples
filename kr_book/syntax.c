/* Exercise 1-24 */

#include <stdio.h>

void check_balance(FILE *file);

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

    check_balance(file);
    
    fclose(file);

    return 0;
}

void check_balance(FILE *file)
{
    char c;
    int parens = 0;
    int line_counter = 1;
    int error_line = -1;

    // read the file one char at a time and check for balance
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '(')
        {
            parens++;
        }
        else if (c == ')')
        {
            parens--;
            if (parens < 0 && error_line == -1)
            {
                // Found more ')' than '('
                error_line = line_counter;
            }
        }

        if (c == '\n')
        {
            ++line_counter;
        }
    }

    if (parens == 0 && error_line == -1)
    {
        printf("Parentheses () are balanced.\n");
    }
    else if (error_line != -1)
    {
        printf("Unbalanced: extra ')' detected at line %i.\n", error_line);
    }
    else
    {
        printf("Unbalanced: missing ')' before end of file (opened at or before line %i).\n", line_counter);
    }
    // TO-DO: add other balance checks [] {} etc.
    // Keep track of what line any parentheses are missing
}
