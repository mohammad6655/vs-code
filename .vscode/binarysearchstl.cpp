#include <iostream>
#include <algorithm>

int main()
{
    int a[8] = {1, 5, 8, 2, 6, 7, 3, 4};
    int size = 8;
    int key = 15;

    std::sort(a, a + size);

    if (std::binary_search(a, a + size, key))
        std::cout << "found ";
    else
        std::cout << "not found ";
}