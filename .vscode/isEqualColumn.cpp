#include <iostream>
#include <conio.h>

const int n = 3;
const int m = 3;

void readA2D(int[][m], int, int);
bool isUpTri(int[][m], int, int);
bool isDownTri(int[][m], int, int);
int isEqualRow(int[][m], int, int);
int isEqualColumn(int[][m], int, int);
void printA2D(int[][m], int, int);
int main()
{
    int arr1[n][m];
    readA2D(arr1, n, m);
    printA2D(arr1, n, m);
    if (isUpTri(arr1, n, m) == true)
    {
        std::cout << "\nUpper Tringle";
    }
    else
    {
        std::cout << "\nnot Upper Tringle";
    }
    if (isDownTri(arr1, n, m) == true)
    {
        std::cout << "\nDown Tringle";
    }
    else
    {
        std::cout << "\nnot Down Tringle";
    }
    if (isDownTri(arr1, n, m) == true && isUpTri(arr1, n, m) == true)
    {
        std::cout << "\nDown and up Tringle";
    }
    else
    {
        std::cout << "\nnot Down and up Tringle";
    }
    int res = isEqualRow(arr1, n, m);
    if (res == -1)
    {
        std::cout << "\nEqual Each Row";
    }
    else
    {
        std::cout << "\nnot Equal row" << '\n';
    }
    res = isEqualColumn(arr1, n, m);
    if (res == -1)
    {
        std::cout << "\nEqual Each Column";
    }
    else
    {
        std::cout << "\nnot Equal Column" << (res + 1);
    }
    return 0;
}
void readA2D(int arr[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " number for row [" << (i + 1) << "]:";
        for (int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
        }
    }
}
void printA2D(int arr[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n\n";
    }
    std::cout << "-------------------------\n";
}
bool isUpTri(int a[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
            if (a[i][j] != 0)
                return false;
    }
    return true;
}
bool isDownTri(int a[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i - 1; j++)
            if (a[i][j] != 0)
                return false;
    }
    return true;
}
int isEqualRow(int a[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (a[i][j] != a[i][0])
                return i;
    }
    return -1;
}
int isEqualColumn(int a[][m], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            if (a[i][j] != a[0][j])
                return j;
    }
    return -1;
}