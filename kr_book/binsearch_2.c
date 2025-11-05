/* Exercise 3-1 */

#include <stdio.h>

#define SIZE 10
#define NOT_FOUND -1

int binsearch(int x, int v[], int n);

int main(void)
{
    int x = 18; // searching for this
    int num_array[SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    if (binsearch(x, num_array, SIZE) == NOT_FOUND)
    {
        printf("%d not found.\n", x);
    }
    else
    {
        printf("%d found.\n", x);
    }
}

// binsearch: find x in v[0] <= v[1] <= ... <=v[n - 1] (array must be sorted)
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (v[high] == x) // match found
    {
        return high;
    }
    else
    {
        return -1; // no match
    }
}
