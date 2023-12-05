#include <iostream>

void insertionSortRecursive(int x[], int n);

int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    int n = 6;
    insertionSortRecursive(a, n);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << "\t";
}
void insertionSortRecursive(int x[], int n)
{
    int last, j;
    if (n <= 1)
        return;

    insertionSortRecursive(x, n - 1);
    last = x[n - 1];
    j = n - 2;
    while (j >= 0 && x[j] > last)
    {
        x[j + 1] = x[j];
        j--;
    }
    x[j + 1] = last;
}