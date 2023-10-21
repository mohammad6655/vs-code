#include <iostream>
void action(int a[], int loc, int n);
int main()
{
    int i, a[100], mid, n, sign = -1;

    std::cout << "Enter n: ";
    std::cin >> n;
    mid = n / 2;
    for (i = 0; i < n; i++)
    {
        std::cout << "Enter a[" << i + 1 << "]:";
        std::cin >> a[i];
    }
    for (i = 0; i <= mid; i++)
    {
        if (a[mid + (sign * i)] != 0)
        {
            action(a, mid + (sign * i), n);
            break;
        }
        if (sign == 1)
            i--;
        sign = -sign;
    }
    if (i > mid)
        std::cout << '\n'
                  << "All element are zero";
    return 0;
}
void action(int a[], int loc, int n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << "\n"
                  << a[i] << " / " << a[loc] << "  =" << (float)a[i] / a[loc];
}