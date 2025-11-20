/* Sample 5.7
 * Multi-dimensional arrays
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
    // TODO: Implement function calls
}

// day_of_year: set day of year from month and day
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
    {
        day += daytable[leap][i];
    }
    return day;
}

// month_day: set month and day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytable[leap][i]; i++)
    {
        yearday -= daytable[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}
