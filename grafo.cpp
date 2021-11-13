#include <iostream>
#include "grafo.h"
using namespace std;

vector<list<pair<double, int>>> listaAdj(TAMANHO);

void Grafo::adicionar(int cidade1, int cidade2, double peso)
{
    listaAdj[cidade1].push_back(make_pair(peso, cidade2));
    listaAdj[cidade2].push_back(make_pair(peso, cidade1));
}

void Grafo::imprimirGrafo(int nVertice)
{
    for (int i = 0; i < nVertice; i++)
    {
        cout << i << ": ";
        for (auto j : listaAdj[i])
        {
            cout << "[" << j.first << "km, " << j.second << "] ";
        }
        cout << endl;
        cout << endl;
    }
}

void Grafo::buscaEmLargura()
{
    static queue<int> q;
    while (!q.empty())
    {                       /* Expand every node in the queue(open set). */
        int p = q.front(); /* Choose a node to expand. */
        q.pop();            /* Pop this node off the queue, */
    }
}
