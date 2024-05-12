#include <iostream>

void readArray(int a[], int n)
{
    std::cout << "Enter " << n << " numbers:";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            std::cout << a[i] << '\t';
    }
    std::cout << '\n';
}
int find(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int diff(int a[], int b[], int n, int c[])
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (find(b, n, a[i]) == -1)
        {
            if (find(c, n, a[i]) == -1)
            {
                j++;
                c[j] = a[i];
            }
        }
    }
    return ++j;
}
int share(int a[], int b[], int n, int c[])
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (find(a, n, b[i]) != -1)
        {
            if (find(c, n, b[i]) == -1)
            {
                j++;
                c[j] = b[i];
            }
        }
    }
    return ++j;
}
int union1(int a[], int b[], int n, int c[])
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (find(c, n, a[i]) == -1)
        {
            j++;
            c[j] = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (find(c, n, b[i]) == -1)
        {
            j++;
            c[j] = b[i];
        }
    }
    return ++j;
}
void init(int c[], int n)
{
    for (int i = 0; i < n; i++)
        c[i] = 0;
}
int menu()
{
    std::cout << "\n";
    std::cout << "\t1:Read array 1\n";
    std::cout << "\t2:Read array 2\n";
    std::cout << "\t3:Find Share\n";
    std::cout << "\t4:Find Union\n";
    std::cout << "\t5:Find differnce a from b\n";
    std::cout << "\t6:Find differnce b from a\n";
    std::cout << "\t7:Exit \n";
    std::cout << " Select 1 to 7 :";
    int choice;
    std::cin >> choice;
    return choice;
}
int main()
{
    const int n = 7;
    int a[n], b[n], c[2 * n] = {0};
    int k = 2 * n, choice;
    for (;;)
    {
        choice = menu();
        if (choice == 7)
            break;

        switch (choice)
        {
        case 1:
            readArray(a, n);
            break;
        case 2:
            readArray(b, n);
            break;
        case 3:
            k = share(b, a, n, c);
            printArray(a, n);
            printArray(b, n);
            printArray(c, k);
            init(c, 2 * n);
            break;
        case 4:
            k = union1(a, b, n, c);
            printArray(a, n);
            printArray(b, n);
            printArray(c, k);
            init(c, 2 * n);
            break;
        case 5:
            k = diff(a, b, n, c);
            printArray(a, n);
            printArray(b, n);
            printArray(c, k);
            init(c, 2 * n);
            break;
        case 6:
            k = diff(b, a, n, c);
            printArray(a, n);
            printArray(b, n);
            printArray(c, k);
            init(c, 2 * n);
            break;
        }
    }
    return 0;
}