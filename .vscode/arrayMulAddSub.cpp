#include <iostream>
#include <stdlib.h>
#include <conio.h>

const int n = 3;
const int m = 3;

void readA2D(int[][m], int, int);
void addArr(int[][m], int[][m], int[][m], int, int);
void subArr(int[][m], int[][m], int[][m], int, int);
void mulArr(int[][m], int[][m], int[][m], int, int);
void scalarMulArr(int arr1[][m], int arr2[][m], int n, int m, int value);
void scalarCalArr(int arr1[][m], int arr2[][m], int n, int m, int value);
void printA2D(int[][m], int, int);
int menu()
{
    int choice;
    std::cout << "\n\t\t1.Read array A" << '\n';
    std::cout << "\t\t2.Read array B" << '\n';
    std::cout << "\t\t3.Display array A" << '\n';
    std::cout << "\t\t4.Display array B" << '\n';
    std::cout << "\t\t5.Add array" << '\n';
    std::cout << "\t\t6.Sub array" << '\n';
    std::cout << "\t\t7.Mul array" << '\n';
    std::cout << "\t\t8.N*A-M*B+K" << '\n';
    std::cout << "\t\t9.Exit" << '\n';
    std::cout << "\tSelect 1 to 9: ";
    std::cin >> choice;
    return choice;
}

int main()
{
    int arr1[n][m], arr2[n][m], arr3[n][m], choice;
    while (1)
    {
        system("cls");
        choice = menu();
        switch (choice)
        {
        case 1:
            readA2D(arr1, n, m);
            break;
        case 2:
            readA2D(arr2, n, m);
            break;
        case 3:
            std::cout << "\t\t A  \n";
            printA2D(arr1, n, m);
            break;
        case 4:
            std::cout << "\t\t B \n";
            printA2D(arr2, n, m);
            break;
        case 5:
            std::cout << "\t\t A \n";
            printA2D(arr1, n, m);
            std::cout << "\t\t B \n";
            printA2D(arr2, n, m);
            std::cout << "\n\t\t A + B \n\n";
            addArr(arr1, arr2, arr3, n, m);
            printA2D(arr3, n, m);
            break;
        case 6:
            printA2D(arr1, n, m);
            std::cout << "\t\t B \n";
            printA2D(arr2, n, m);
            std::cout << "\t A - B\n";
            subArr(arr1, arr2, arr3, n, m);
            printA2D(arr3, n, m);
            break;
        case 7:
            std::cout << "\t\t A \n";
            printA2D(arr1, n, m);
            std::cout << "\t\t B \n";
            printA2D(arr2, n, m);
            std::cout << "\t\t A * B \n";
            mulArr(arr1, arr2, arr3, n, m);
            printA2D(arr3, n, m);
            break;
        case 8:
            int M, N, K;
            std::cout << "Enter N, M, K: ";
            std::cin >> N >> M >> K;
            scalarMulArr(arr1, arr3, n, m, N);
            std::cout << "\t\t A \n";
            printA2D(arr1, n, m);
            std::cout << "\t\t B \n";
            printA2D(arr2, n, m);
            std::cout << "\t\tN * A \n";
            printA2D(arr3, n, m);
            std::cout << "\t\t -M * B\n";
            int arr4[n][m];
            scalarMulArr(arr2, arr4, n, m, -M);
            printA2D(arr4, n, m);
            std::cout << "\t\tN * A - M * B\n";
            addArr(arr4, arr3, arr3, n, m);
            printA2D(arr3, n, m);
            scalarCalArr(arr3, arr3, n, m, K);
            std::cout << "\t\tN * A - M * B + K\n";
            printA2D(arr3, n, m);
            break;
        case 9:
            exit(0);
            break;
        }
    }
}
void readA2D(int a[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter " << m << " numbers for row [" << (i + 1) << "]:";
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }
}
void addArr(int arr1[][m], int arr2[][m], int arr3[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
void subArr(int arr1[][m], int arr2[][m], int arr3[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}
void mulArr(int arr1[][m], int arr2[][m], int arr3[][m], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int s = 0;
            for (int k = 0; k < m; k++)
            {
                s = s + arr1[i][k] * arr2[k][j];
            }
            arr3[i][j] = s;
        }
}
void scalarMulArr(int arr1[][m], int arr2[][m], int n, int m, int value)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            arr2[i][j] = arr1[i][j] * value;
        }
}
void scalarCalArr(int arr1[][m], int arr2[][m], int n, int m, int value)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            arr2[i][j] = arr1[i][j] + value;
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
        std::cout << "\n";
    }
    std::cout << "----------------------------------------------------\n";
}