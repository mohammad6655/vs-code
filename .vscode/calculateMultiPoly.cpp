#include <iostream>

#define MAX 20

struct poly
{
    int base, pow;
};
void readpoly(struct poly p[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        std::cout << "\n\tEnter base & pow:";
        std::cin >> p[i].base >> p[i].pow;
        if (p[i].base == 0 && p[i].pow == 0)
            break;
    }
}
void sortpoly(struct poly p[MAX])
{
    struct poly temp;
    int i, j;
    for (i = 0; i < MAX - 1; i++)
        for (j = i + 1; j < MAX; j++)
            if (p[i].pow < p[j].pow)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}
void writepoly(struct poly p[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (p[i].base == 0 && p[i].pow == 0)
            break;
        else if (i != 0)
            std::cout << " + ";
        std::cout << p[i].base << "X^ " << p[i].pow;
    }
}
void addpoly(struct poly p1[MAX], struct poly p2[MAX], struct poly p3[MAX])
{
    int ip1 = 0, ip2 = 0, ip3 = 0;
    while (1)
    {
        if (p1[ip1].base == 0 && p2[ip2].base == 0)
            break;
        else if (p1[ip1].pow == p2[ip2].pow)
        {
            p3[ip3].pow = p2[ip2].pow;
            p3[ip3].base = p1[ip1].base + p2[ip2].base;
            ip1++;
            ip2++;
            ip3++;
        }
        else if (p1[ip1].pow > p2[ip1].pow)
        {
            p3[ip3].pow = p1[ip1].pow;
            p3[ip3].base = p1[ip1].base;
            ip1++;
            ip3++;
        }
        else
        {
            p3[ip3].pow = p2[ip2].pow;
            p3[ip3].base = p2[ip2].base;
            ip2++;
            ip3++;
        }
    }
}
int main()
{
    struct poly a[MAX] = {0}, b[MAX] = {0}, c[MAX] = {0};
    std::cout << "\nEnter base & pow for poly a:";
    readpoly(a);
    std::cout << "\nEnter base & pow for poly b:";
    readpoly(b);
    sortpoly(a);
    sortpoly(b);
    std::cout << "\nPoly a = ";
    writepoly(a);
    std::cout << "\nPoly b = ";
    writepoly(b);
    addpoly(a, b, c);
    std::cout << "\nPoly c = ";
    writepoly(c);
    return 0;
}