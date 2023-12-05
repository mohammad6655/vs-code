#include <iostream>

void readA2D(int a[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " number for row[" << i << "]: ";
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }
}
void printA2D(int a[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << "\t";
        std::cout << '\n';
    }
}
double MulPer(int a[][4], int n, int m)
{
    double mul = 1;
    for (int j = 0; j < m; j++)
    {
        if (a[0][j] != 0)
            mul = mul * a[0][j];
        if (a[n - 1][j] != 0)
            mul = mul * a[n - 1][j];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i][0] != 0)
            mul = mul * a[i][0];
        if (a[i][m - 1] != 0)
            mul = mul * a[i][m - 1];
    }
    return mul;
}
int main()
{
    const int n = 4;
    const int m = 4;
    int a[n][m];
    readA2D(a, n, m);
    printA2D(a, n, m);
    std::cout << "Multiply is " << MulPer(a, n, m);
    return 0;
}