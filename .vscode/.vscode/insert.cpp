#include <iostream>
#include <conio.h>

int insert(int a[], int key, int n, int c)
{
    if (n >= c)
        return n;
    a[n] = key;
    return n + 1;
}
int main()
{
    int a[10], n, c;
    std::cout << "Enter number of array(less if 10 number): ";
    std::cin >> c;
    std::cout << "Enter array: ";
    for (int i = 0; i < c; i++)
        std::cin >> a[i];
    n = c;
    int key = 13;
    n = insert(a, key, n, c);
    for (int i = 0; i < n; i++)
        std::cout << a[i];
}