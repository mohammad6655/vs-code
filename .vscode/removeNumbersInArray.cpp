#include <iostream>

void readArray(int a[], int n)
{
    std::cout << "Enter " << n << " number: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
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
void removeAll(int a[], int &n, int value)
{
    for (;;)
    {
        int l = find(a, n, value);
        if (l >= 0)
        {
            for (int i = l; i < n; i++)
            {
                a[i] = a[i + 1];
            }
            a[n - 1] = 0;
            n--;
        }
        else
            break;
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\t";
    std::cout << '\n';
}
int main()
{
    int const n = 10;
    int m = n;
    int x[n];
    readArray(x, n);
    int y;
    std::cout << "Enter a value for remove: ";
    std::cin >> y;
    removeAll(x, m, y);
    printArray(x, m);
    return 0;
}