// DFS
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define MAX 50

int stack[MAX];
int top = -1;
int vertex;
int m[MAX][MAX]; // adjacency matrix
int vs[MAX];     // vertex_status

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int v)
{
    if (top == (MAX - 1))
    {
        std::cout << "Stack Overflow\n";
        return;
    }
    top = top + 1;
    stack[top] = v;
}
int pop()
{
    int v;
    if (top == -1)
    {
        std::cout << "Stack Underflow\n";
        exit(1);
    }
    else
    {
        v = stack[top];
        top = top - 1;
        return v;
    }
}
void DFS_util(int v)
{
    int i;
    push(v);

    while (!isEmpty())
    {
        v = pop();
        if (vs[v] == 1)
        {
            std::cout << v << " ";
            vs[v] = 2; // VISITED
        }
        for (i = vertex - 1; i >= 0; i--)
        {
            if (m[v][i] == 1 && vs[i] == 1)
                push(i);
        }
    }
}
void DFS()
{
    int i;
    for (i = 0; i < vertex; i++)
        vs[i] = 1;

    std::cout << "Starting Vertex: ";
    std::cin >> i;

    DFS_util(i);

    std::cout << "\n";
}
void create()
{
    int count, me, source, dest;

    std::cout << "Enter total number of vertex: ";
    std::cin >> vertex;

    me = vertex * (vertex - 1); // maximum edge

    for (count = 0; count < me; count++)
    {
        std::cout << "src : ";
        std::cin >> source;

        std::cout << "dsc : ";
        std::cin >> dest;

        std::cout << '\n';

        if ((source == -1) && (dest == -1))
            break;
        if (source >= vertex || dest >= vertex || source < 0 || dest < 0)
        {
            std::cout << "Invalid\n";
            count--;
        }
        else
            m[source][dest] = 1;
    }
}
int main()
{
    /*
            0 - 1 - 2
            |   |   |
            3 - 4 - 5

    */

    create();
    DFS();

    getch();
}