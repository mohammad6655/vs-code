// mergesort
#include <bits/stdc++.h>

int main()
{
    std::vector<int> a = {10, 6, 12};

    std::vector<int> b = {1, 15, 30, 10};

    std::vector<int> c(7);

    std::sort(a.begin(), a.end());

    std::sort(a.begin(), b.begin());

    std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    for (int i = 0; i < c.size(); i++)
        std::cout << c[i] << "   ";
}