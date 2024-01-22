#include <iostream>
#include <conio.h>
#include <iomanip>

void readA2D(int x[3][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " number for row " << (i + 1) << ":";
        for (int j = 0; j < m; j++)
            std::cin >> x[i][j];
    }
}
void ZArray(int x[3][4], int y[3][4], int z[3][4], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            z[i][j] = 2 * x[i][j] - 3 * y[i][j];
        }
}
void printA2D(int x[3][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << x[i][j] << '\t';
        std::cout << '\n';
    }
}
int main()
{
    int x[3][4], y[3][4], z[3][4];
    readA2D(x, 3, 4);
    readA2D(y, 3, 4);
    ZArray(x, y, z, 3, 4);
    std::cout << "\n\t Array x " << '\n';
    printA2D(x, 3, 4);
    std::cout << "\n\t Arrray y " << '\n';
    printA2D(y, 3, 4);
    std::cout << "\n\t Array z " << '\n';
    printA2D(z, 3, 4);
    return 0;
}