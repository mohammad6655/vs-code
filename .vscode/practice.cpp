#include <iostream>

void readArray(int a[], int n)
{
    std::cout << "Enter " << n << " numbers:";
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}
int menu()
{
    std::cout << "\n";
    std::cout << "\t1:Read array 1\n";
    std::cout << "\t2:Read array 2\n";
    std::cout << "\t3:Find Share\n";
    std::cout << "\t4:Find Union\n";
    std::cout << "\t5:Find differnce a from b\n";
    std::cout << "\t6:Find differnce b from a\n";
    std::cout << "\t7:Exit \n";
    std::cout << " Select 1 to 7 :";
    int choice;
    std::cin >> choice;
    return choice;
}
int main()
{
    const int n = 7;
    int a[n], b[n], c[2 * n] = {0};
    int k = 2 * n, choice;
    for (;;)
    {
        choice = menu();
        if (choice = 7)
            break;
    }
    switch ((choice))
    {
    case 1:
        readArray(a, n);
        break;
    case 2:
        readArray(b, n);
        break;
    }
    return 0;
}