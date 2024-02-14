// heap sort
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> h = {1, 5, 3, 4, 7};

    std::make_heap(h.begin(), h.end());

    std::sort_heap(h.begin(), h.end());

    for (int &a : h)
        std::cout << a << " ";
}