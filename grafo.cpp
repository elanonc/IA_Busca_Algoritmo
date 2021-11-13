#ifndef GRAFO_CPP
#define GRAFO_CPP

#include <iostream>
#include "grafo.h"
using namespace std;

vector<list<pair<int, int>>> listaAdj(TAMANHO);

void adicionar(int cidade1, int cidade2, double peso)
{
    listaAdj[cidade1].push_back(make_pair(peso, cidade2));
    listaAdj[cidade2].push_back(make_pair(peso, cidade1));
    return;
}

void imprimirGrafo(int nVertice)
{
    for (int i = 0; i < nVertice; i++)
    {
        cout << i << ": ";
        for (auto j : listaAdj[i])
        {
            cout << "[" << j.first << " " << j.second << "km] ";
        }
        cout << endl;
        cout << endl;
    }
}

#endif