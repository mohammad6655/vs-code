#include <iostream>

void readA2D(int a[][6], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " number for row[" << i << "]:";
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }
}
void printA2D(int a[][6], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << "\t";
        std::cout << '\n';
    }
}
double mulNotPer(int a[][6], int n, int m)
{
    double mul = 1;
    for (int i = 1; i <= n - 2; i++)
        for (int j = 1; j <= m - 2; j++)
        {
            if (a[i][j] != 0)
                mul = mul * a[i][j];
        }
    return mul;
}
int main()
{
    const int n = 5;
    const int m = 6;
    int a[n][m];
    readA2D(a, n, m);
    printA2D(a, n, m);
    std::cout << "Multiply is " << mulNotPer(a, n, m);
    return 0;
}