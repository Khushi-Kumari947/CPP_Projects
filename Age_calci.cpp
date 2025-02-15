#include <stdio.h>
#include <stdlib.h>

struct cur_date {
    int cur_date;
    int cur_month;
    int cur_year;
} cd;

struct dob {
    int date;
    int month;
    int year;
} dob;

int lp_year(int y) {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

int days(int m, int y) {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && lp_year(y)) return 29; // Leap year check
    return monthDays[m - 1];
}

int* getAge(int d, int m, int y) {
    int *age = (int*)malloc(3 * sizeof(int));
    int age_days, age_m, age_yr;

    // If birth date is greater than current date, borrow days from previous month
    if (d > cd.cur_date) {
        cd.cur_date += days(cd.cur_month - 1, cd.cur_year);
        cd.cur_month -= 1;
    }

    // If birth month is greater than current month, borrow months from previous year
    if (m > cd.cur_month) {
        cd.cur_month += 12;
        cd.cur_year -= 1;
    }

    // Calculate final age
    age_days = cd.cur_date - d;
    age_m = cd.cur_month - m;
    age_yr = cd.cur_year - y;

    age[0] = age_days;
    age[1] = age_m;
    age[2] = age_yr;

    return age;
}

int main() {
    printf("Enter current date:\n");
    printf("Date: ");
    scanf("%d", &cd.cur_date);
    printf("Month: ");
    scanf("%d", &cd.cur_month);
    printf("Year: ");
    scanf("%d", &cd.cur_year);

    printf("\nEnter date of birth:\n");
    printf("Date: ");
    scanf("%d", &dob.date);
    printf("Month: ");
    scanf("%d", &dob.month);
    printf("Year: ");
    scanf("%d", &dob.year);

    int *p = getAge(dob.date, dob.month, dob.year);

    printf("\nThe age in terms of days, months, and years is:\n");
    printf("Day(s): %d\n", p[0]);
    printf("Month(s): %d\n", p[1]);
    printf("Year(s): %d\n", p[2]);

    free(p); // Free allocated memory
    return 0;
}
