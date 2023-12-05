#include <iostream>

void readA2D(int a[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " number for row[" << i << "]:";
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
double sumMS(int a[][4], int n, int m)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == j || i + j == n - 1)
                sum = sum + a[i][j];
        }
    return sum;
}
int sumPer(int a[][4], int n, int m)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum = sum + a[0][j];
        sum = sum + a[n - 1][j];
    }
    for (int i = 1; i < n - 1; i++)
    {
        sum = sum + a[i][0];
        sum = sum + a[i][m - 1];
    }
    return sum;
}
bool Equal(int a[][4], int n, int m)
{
    return (sumPer(a, n, m) == sumMS(a, n, m));
}
int main()
{
    const int n = 4;
    const int m = 4;
    int a[n][m];
    readA2D(a, n, m);
    printA2D(a, n, m);
    if (Equal(a, n, m) == true)
        std::cout << "Yes";
    else
        std::cout << "No";
    return 0;
}