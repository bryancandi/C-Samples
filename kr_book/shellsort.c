/* Sample 3.5
 * shellsort - sort v[0]...v[n-1] into increasing order
 */

#include <stdio.h>

#define SIZE 6

void shellsort(int v[], int n);

int main(void)
{
    int num_array[] = {37, 12, 89, 24, 45, 9};
    int size = SIZE;

    printf("Before sort:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num_array[i]);
    }
    printf("\n\n");

    shellsort(num_array, SIZE);

    printf("After sort:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num_array[i]);
    }
    printf("\n");

    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}
