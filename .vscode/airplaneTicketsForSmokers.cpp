#include <iostream>
#include <string.h>
#include <conio.h>

#define M 10
#define N 40

void initArray(int a[N][M])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            a[i][j] = 0;
}
void printArray(int a[N][M])
{
    int i, j;
    std::cout << "\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            std::cout << a[i][j] << "   ";
        std::cout << "\n";
    }
}
int setSmokeArray(int a[N][M], int flyNo, int code)
{
    int i;
    for (i = 0; i < N / 2; i++)
        if (a[i][flyNo] == 0)
        {
            a[i][flyNo] = code;
            return (0);
        }
    return (1);
}
int setNotSmokleArray(int a[N][M], int flyNo, int code)
{
    int i;
    for (i = N / 2; i < N; i++)
        if (a[i][flyNo] == 0)
        {
            a[i][flyNo] = code;
            return (0);
        }
    return (1);
}

int main()
{
    int code, smoke, flyNo, a[N][M], ret;
    char ch;
    initArray(a);
    while (1)
    {
        std::cout << "Enter Code, Smoke[0 or 1] and Fly Number: ";
        std::cin >> code >> smoke >> flyNo;
        flyNo--;
        if (flyNo >= M || flyNo < 0)
            std::cout << "Enter Fly number 1 to " << M;
        else if (smoke)
        {
            ret = setSmokeArray(a, flyNo, code);
            if (ret == 1)
            {
                std::cout << "\nAre you want sit in not smoke part: ";
                ch = getche();
                if (ch == 'y' || ch == 'Y')
                    ret = setNotSmokleArray(a, flyNo, code);
                if (ret == 1)
                    std::cout << flyNo << " is full";
            }
        }
        else
        {
            ret = setNotSmokleArray(a, flyNo, code);
            if (ret == 1)
            {
                std::cout << "\nAre you want sit in smoke part: ";
                ch = getche();
                if (ch == 'y' || ch == 'Y')
                    ret = setSmokeArray(a, flyNo, code);
                if (ret == 1)
                    std::cout << flyNo << " is full";
            }
        }
        std::cout << "Continue ?";
        ch = getche();
        std::cout << '\n';
        if (ch == 'N' || ch == 'n')
            break;
    }
    printArray(a);
    return 0;
}