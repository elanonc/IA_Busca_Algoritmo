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

void Grafo::buscaEmLargura(int raiz, int objetivo)
{
    bool *explorados = new bool[tam]; // Cidades já visitadas.

    for (int i = 0; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    queue<int> borda;        // É uma fila.
    explorados[raiz] = true; // Colocando a raiz como explorada.
    borda.push(raiz);        // iniciando a borda.
    int no;

    while (!borda.empty())
    {

        no = borda.front(); // retirando o que está a mais tempo na fila.
        cout << no << " ";
        borda.pop();
        list<pair<double, int>> lista = listaAdj[no];
        for (auto j : lista)
        {
            int val = j.second; // Cidades vizinhas.
            if (val == objetivo)
                return;
            if (!explorados[val])
            {
                explorados[val] = true; // Adicionando ao explorados.
                borda.push(val);
            }
        }
    }
    cout << endl;
}
