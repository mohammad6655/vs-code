#include <iostream>

void append(int a[], int *m, int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i + *m] = b[i];
    (*m) = n + *m;
}
void read(int a[], int n)
{
    int i;
    std::cout << "Enter " << n << " numbers: ";
    for (i = 0; i < n; i++)
        std::cin >> a[i];
}
void print(int a[], int n)
{
    int i;
    std::cout << "Array is: ";
    for (i = 0; i < n; i++)
        std::cout << "    " << a[i];
}
int main()
{
    int num1[100], num2[100], n, m;
    std::cout << "Enter m: ";
    std::cin >> m;
    read(num1, m);
    std::cout << "Enter n: ";
    std::cin >> n;
    read(num2, n);
    append(num1, &m, num2, n);
    print(num1, m);
    return 0;
}