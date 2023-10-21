#include <iostream>

void read(int[], int);
double pow(double, int);
int main()
{
    int a[100] = {0}, n;
    double x, sum = 0;
    std::cout << "Enter x, n : ";
    std::cin >> x >> n;
    read(a, n);
    for (int i = 0; i <= n; i++)
        if (a[i] != 0)
            sum += a[i] * pow(x, i);
    print(a, n);
    std::cout << "\nSum is: " << sum;
    return 0;
}
void read(int a[], int n)
{
    int location, zarib;
    while (1)
    {
        std::cout << "Enter location and zarib: ";
        std::cin >> location >> zarib;
        if (location == -1)
            break;
        if (location < n)
            a[location] = zarib;
        else
            std::cout << "location less than equqal " << n;
    }
}
double pow(double x, int n)
{
    double pow1 = 1.0;
    for (int i = 1; i <= n; i++)
        pow1 *= x;
    return pow1;
}
void print(int a[], int n)
{
    int i;
    std::cout << "P = ";
    for (i = n; i >= 0; i--)
        if (a[i] != 0)
            if (i != 0)
                std::cout << " " << a[i] << "X^" << i << " + ";
            else
                std::cout << " " << a[i] << "X^" << i;
}