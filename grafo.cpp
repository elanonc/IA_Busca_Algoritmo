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
        for (auto j : listaAdj[i])
        {
            cout << "[" << j.first << "km, " << j.second << "] ";
        }
        cout << endl;
        cout << endl;
    }
}

void Grafo::buscaEmLargura(int raiz, int destino)
{
    bool *visitado = new bool[tam];
    for (int i = 0; i < tam; i++)
        visitado[i] = false;
    queue<int> fila;
    visitado[raiz] = true;
    fila.push(raiz);

    while (!fila.empty())
    {
        raiz = fila.front();
        cout << raiz << " ";
        fila.pop();
        list<pair<double, int>> lista = listaAdj[raiz];
        for (auto j : lista)
        {
            int val = j.second;
            if (!visitado[val])
            {
                visitado[val] = true;
                fila.push(val);
            }
        }
    }
    cout << endl;
}
