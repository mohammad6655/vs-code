#include <iostream>

void readArray(int x[], int n)
{
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }
}
int Count(int x[], int n, int value)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == value)
            c++;
    }
    return c;
}
void allIndex(int x[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] == value)
            std::cout << i << "\t";
    }
}
int main()
{
    const int n = 5;
    int a[n] = {0};
    readArray(a, n);
    std::cout << "Enter a number for Search: ";
    int b;
    std::cin >> b;
    std::cout << "Count " << b << " is " << Count(a, n, b) << " in position(s) ";
    allIndex(a, n, b);
    return 0;
}