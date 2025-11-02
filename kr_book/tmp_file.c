









#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

void check_balance(FILE *file);
void remove_comments(FILE *src_file, FILE *tmp_file);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }

    FILE *src_file = fopen(argv[1], "rb");
    if (!src_file)
    {
        printf("Source file '%s' does not exist\n", argv[1]);
        return 2;
    }

    FILE *tmp_file = fopen("tmp_file.c", "wb+");
    if (!tmp_file)
    {
        printf("Cannot create temporary file\n");
        fclose(src_file);
        return 3;
    }

    remove_comments(src_file, tmp_file);

    
    rewind(tmp_file);

    check_balance(tmp_file);
    
    fclose(src_file);
    fclose(tmp_file);

    
    

    return 0;
}

void remove_comments(FILE *src_file, FILE *tmp_file)
{
    int c, next, nnext;

    while ((c = fgetc(src_file)) != EOF)
    {
        if (c == '/')
        {
            next = fgetc(src_file);
            if (next == '*')
            {
                
                while ((c = fgetc(src_file)) != EOF)
                {
                    if (c == '\n')
                    {
                        fputc('\n', tmp_file); 
                    }
                    if (c == '*')
                    {
                        nnext = fgetc(src_file);
                        if (nnext == '/')
                        {
                            break;
                        }
                        else
                        {
                            
                            ungetc(nnext, src_file);
                        }
                    }
                }
            }
            else if (next == '/')
            {
                
                while ((c = fgetc(src_file)) != EOF && c != '\n')
                    ;
                if (c == '\n')
                {
                    fputc('\n', tmp_file);
                }
            }
            else
            {
                
                fputc('/', tmp_file);
                fputc(next, tmp_file);
            }
        }
        else
        {
            fputc(c, tmp_file);
        }
    }
}

void check_balance(FILE *file)
{
    char c;
    int parens = 0;
    int line_counter = 1;
    int error_line = -1;

    
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
    
    
}
