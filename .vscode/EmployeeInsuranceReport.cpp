#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct date
{
    int year, month, day;
};
struct custom_insure
{
    int code;
    char name[30];
    struct date date1;
};
void gets_info(struct custom_insure custom1[], int n)
{
    char s[20];
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << "Enter code [" << i + 1 << "]:";
        gets(s);
        custom1[i].code = atoi(s);
        std::cout << "Enter name [" << i + 1 << "]:";
        gets(custom1[i].name);
        std::cout << "Enter date(yy/mm/dd)[" << i + 1 << "]:";
        std::cin >> custom1[i].date1.year >> custom1[i].date1.month >> custom1[i].date1.day;
        getchar();
    }
}
void puts_info(struct custom_insure custom1[], int n)
{
    int i, year1, month1, day1, yy, mm, dd, carry_month, carry_year;
    std::cout << "Enter date(yy/mm/dd): ";
    std::cin >> year1 >> month1 >> day1;
    std::cout << "\nCode\t Name\t\tDate\t\tWork data";
    std::cout << "\n====\t=====\t\t======\t\t======";
    for (i = 0; i < n; i++)
    {
        carry_month = 0;
        carry_year = 0;
        if (custom1[i].date1.day > day1)
        {
            dd = day1 + 30 - custom1[i].date1.day;
            carry_month = 1;
        }
        else
            dd = day1 - custom1[i].date1.day;
        if (custom1[i].date1.month > month1)
        {
            mm = month1 + 12 - custom1[i].date1.month - carry_month;
            carry_year = 1;
        }
        else
            mm = month1 - custom1[i].date1.month - carry_month;
        yy = year1 - custom1[i].date1.year - carry_year;
        std::cout << "\n"
                  << custom1[i].code << "\t" << custom1[i].name
                  << "\t\t" << custom1[i].date1.year << "/" << custom1[i].date1.month
                  << "/" << custom1[i].date1.day << "\t" << yy << "/" << mm << "/" << dd;
    }
}

int main()
{
    int n;
    struct custom_insure custom1[MAX];
    std::cout << "Enter n(custom number):";
    std::cin >> n;
    getchar();
    gets_info(custom1, n);
    puts_info(custom1, n);
    getchar();
}