#include <iostream>
#include "grafo.h"
using namespace std;

Grafo::Grafo(int tam)
{
    this->tam = tam;
    listaAdj = vector<list<pair<double, int>>>(tam);
}

Grafo::~Grafo()
{
}

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
        for (auto j : this->listaAdj[i])
        {
            cout << "[" << j.first << "km, " << j.second << "] ";
        }
        cout << endl;
        cout << endl;
    }
}

void Grafo::buscaEmLargura(int raiz, int destino)
{
    static queue<caminho> q;
    int cnt = 0;
    /*
    for (int v = raiz; v < listaAdj[v]; ++v)
    {
        /*
        num[v] = pa[v] = -1;
        QUEUEinit(G->V);
        num[s] = cnt++;
        pa[s] = s;
        QUEUEput(s);
    }*/

    if (raiz == destino)
    {
    }

    while (!q.empty())
    { /* Expand every node in the queue(open set). */
        //int p = q.front();
        q.pop(); /* Pop this node off the queue, */
    }
}
