#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

class grafo
{
    
    int v;
    list<int> *adj;
    bool isciclo(int v, bool visitado[], int padre);

public:
    grafo(int v);
    void loadGraph(int v, int w);
    bool isTree();
};

grafo::grafo(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void grafo::loadGraph(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool grafo::isciclo(int v, bool visitado[], int padre)
{
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visitado[*i])
        {
            if (isciclo(*i, visitado, v))
                return true;
        }

        else if (*i != padre)
            return true;
    }
    return false;
}

bool grafo::isTree()
{

    bool *visitado = new bool[v];
    for (int i = 0; i < v; i++)
        visitado[i] = false;

    if (isciclo(0, visitado, -1))
        return false;

    for (int u = 0; u < v; u++)
        if (!visitado[u])
            return false;

    return true;
}

int main()
{
    grafo grafo1(5);
    grafo1.loadGraph(1, 0);
    grafo1.loadGraph(0, 2);
    grafo1.loadGraph(0, 3);
    grafo1.loadGraph(3, 4);
    grafo1.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";

    return 0;
}