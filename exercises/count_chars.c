#include <stdio.h>

// count characters with a for loop (empty body)

int main(void)
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
