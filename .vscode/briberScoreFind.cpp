#include <iostream>
#include <math.h>

int main()
{
    const int N = 10;
    const int M = 5;
    double scores[N][M], err[M] = {0}, m, maxScore = 0;
    std::string names[N];
    int i, j, k, b, c;
    for (i = 0; i < N; i++)
    {
        std::cout << "Enter name and scores of sportman #" << (i + 1) << " :";
        std::cin >> names[i];
        for (j = 0; j < M; j++)
            std::cin >> scores[i][j];
    }
    for (i = 0; i < N; i++)
    {
        m = 0;
        for (j = 0; j < M; j++)
            m += scores[i][j] / M;
        for (j = 0; j < M; j++)
            err[j] += fabs(scores[i][j] - m);
    }
    k = 0;
    for (j = 1; j < M; j++)
        if (err[j] > err[k])
            k = j;
    for (i = 0; i < N; i++)
    {
        m = 0;
        for (j = 0; j < M; j++)
        {
            if (j == k)
                continue;
            m += scores[i][j];
        }
        if (m > maxScore)
        {
            maxScore = m;
            b = i;
        }
    }
    maxScore = 0;
    for (i = 0; i < N; i++)
        if (scores[i][k] > maxScore)
        {
            maxScore = scores[i][k];
            c = i;
        }
    std::cout << "Briber is " << names[c] << '\n';
    std::cout << "Winner is " << names[b] << '\n';
    return 0;
}