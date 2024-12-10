#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct bands
{
    int no;
    char name[30];
    int full;
};
struct bands
    band[MAX];

int menu()
{
    int choose = 0;
    std::cout << "\n1. List number of free band";
    std::cout << "\n2. List free band numbers";
    std::cout << "\n3. List full band numbers";
    std::cout << "\n4. Full band";
    std::cout << "\n5. Free band";
    std::cout << "\n6. Exit";
    std::cout << "\nSelect 1..6:";
    std::cin >> choose;
    return choose;
}
void list1()
{
    int i, count = 0;
    for (i = 0; i < MAX; i++)
        if (band[i].full == 0)
            count++;
    std::cout << "\nNumber of free band is " << count;
}
void list2()
{
    int i;
    std::cout << "\nList of free bunds";
    for (i = 0; i < MAX; i++)
        if (band[i].full == 0)
            std::cout << band[i].no << " ";
}
void list3()
{
    int i;
    for (i = 0; i < MAX; i++)
        if (band[i].full)
            std::cout << "band " << band[i].no << " by full "
                      << band[i].name << '\n';
}
void full()
{
    int num;
    std::cout << "Enter band no(1..20):";
    std::cin >> num;
    if (band[num - 1].full)
    {
        std::cout << "Band is " << num << " full" << '\n';
        std::cin.get();
        return;
    }
    else
    {
        band[num - 1].full = 1;
        std::cout << "Enter bund full by:";
        std::cin >> band[num - 1].name;
    }
}
void free()
{
    int num;
    std::cout << "Enter band no(1..20):";
    std::cin >> num;
    if (band[num - 1].full == 0)
    {
        std::cout << "Band is " << num << " free" << '\n';
        return;
    }
    else
    {
        band[num - 1].full = 0;
        band[num - 1].name[0] = '\0';
    }
}
int main()
{
    int i;
    for (i = 0; i < MAX; i++)
        band[i].no = i + 1;
    while (1)
    {
        switch (menu())
        {
        case 1:
            list1();
            break;
        case 2:
            list2();
            break;
        case 3:
            list3();
            break;
        case 4:
            full();
            break;
        case 5:
            free();
            break;
        case 6:
            return 0;
            break;
        }
    }
    return 0;
}