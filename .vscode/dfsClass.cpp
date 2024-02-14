// DFS CLASS
#include <iostream>
#include <conio.h>
#include <list>

class Graph
{
    int V;
    std::list<int> *adj;
    void f(int v, bool visited[]);

public:
    Graph(int V);
    void add(int v, int w);
    void DFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}
void Graph::add(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::f(int v, bool visited[])
{
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            f(*i, visited);
}
void Graph::DFS()
{
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            f(i, visited);
}

int main()
{
    Graph g(6);
    /*
                0
                |
                1
              /   \
             2     3
            / \
           4   5
    */

    g.add(0, 1);
    g.add(1, 2);
    g.add(1, 3);
    g.add(2, 4);
    g.add(2, 5);

    std::cout << "DFS : ";
    g.DFS();

    getch();
}