/* Sample 3.3 */

#include <stdio.h>

#define SIZE 10
#define NOT_FOUND -1

int binsearch(int x, int v[], int n);

int main(void)
{
    int x = 18; // searching for this
    int n = SIZE;
    int num_array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    if (binsearch(x, num_array, n) == NOT_FOUND)
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
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else // match found
        {
            return mid;
        }
    }
    return -1; // no match
}
