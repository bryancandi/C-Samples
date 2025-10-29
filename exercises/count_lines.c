#include <stdio.h>

// count lines and chars with a for loop
int main(void)
{
    int c, nc, nl;

    for (nc = 0, nl = 0; (c = getchar()) != EOF; ++nc)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("chars: %i\nlines: %i\n", nc, nl);
}
