#include <stdio.h>

#define LOWER 0    // Lower limit of temperature table
#define UPPER 300  // Upper limit
#define STEP 20    // Step size

int main(void)
{
    int fahr;
    
    printf("Fahrenheit to Celsius conversion table:\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        int celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d\t%6d\n", fahr, celsius);
    }
}
