#include <iostream>

int main()
{
    int x[11][3], i, j, n1 = 0, n2 = 0, n4 = 0, n5 = 0, n7 = 0;
    int maxg = 0, maxm = 0, m;
    for (i = 0; i < 11; i++)
    {
        m = 0;
        std::cout << "tedade tala,noghre va boronze sale " << (1385 + i) << " ? ";
        for (j = 0; j < 3; j++)
        {
            std::cin >> x[i][j];
            m += x[i][j];
        }
        n1 += m;
        n2 += x[i][0];
        if (x[i][0] * 3 + x[i][1] * 2 + x[i][2] > 10)
            n7++;
        if (m > maxm)
        {
            maxm = m;
            n4 = i + 1385;
        }
        if (x[i][0] > maxg)
        {
            maxg = x[i][0];
            n5 = i + 1385;
        }
    }
    std::cout << "------------answer (1) ------" << '\n';
    std::cout << n1 << '\n';
    std::cout << "------------answer (2) ------" << '\n';
    std::cout << n2 << '\n';
    std::cout << "------------answer (3) -------" << '\n';
    for (i = 0; i < 11; i++)
        if (x[i][0] + x[i][1] + x[i][2] == 0)
            std::cout << (1385 + i) << '\n';
    std::cout << "------------asnwer (4) ------" << '\n';
    std::cout << n4 << '\n';
    std::cout << "------------answer (5) ------" << '\n';
    std::cout << n5 << '\n';
    std::cout << "------------answer (6) ------" << '\n';
    for (i = 0; i < 11; i++)
        std::cout << "sal " << (1385 + i) << ": poan= " << (x[i][0] * 3 + x[i][1] * 2 + x[i][2]) << '\n';
    std::cout << "------------answer (7) ------" << '\n';
    std::cout << n7 << '\n';
}