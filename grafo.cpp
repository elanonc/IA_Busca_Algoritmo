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
    Arvore arvore;
    No *no;
    queue<No *> borda; // É uma fila.
    no = arvore.inserir(raiz);
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    int estado;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    borda.push(arvore.getRaiz()); // iniciando a borda.
    // cout << arvore.getRaiz()->getEstado() << endl;

    while (!borda.empty())
    {
        // remover elemento da borda.
        no = borda.front();
        borda.pop();                        // retirando o que está a mais tempo na fila.
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.
        // para cada ação aplicável em nó.estado

        list<pair<double, int>> lista = listaAdj[no->getEstado()];
        for (pair<double, int> j : lista)
        {
            estado = j.second; // Cidades vizinhas.
            // cout << estado;
            No *filho = arvore.inserirNo(no, estado);
            if (!explorados[filho->getEstado()] /*|| borda.front() != filho*/)
            {
                if (filho->getEstado() == objetivo)
                {
                    // arvore.imprimir(filho);
                    return;
                }
            }
            borda.push(filho);
        }
    }
}

void Grafo::buscaEmLargura2(int raiz, int objetivo)
{
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    vector<pair<int, int>> caminho;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
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
        // auto
        for (pair<double, int> j : lista)
        {
            int estado = j.second; // Cidades vizinhas.
            caminho.push_back(make_pair(no, estado));
            if (estado == objetivo)
            {
                int indice = caminho.size() - 1;
                cout << endl;
                while (indice != raiz)
                {
                    cout << caminho[indice].first << endl;
                    indice = caminho[indice].first;
                }
                cout << raiz << endl;
                return;
            }

            if (!explorados[estado])
            {
                explorados[estado] = true; // Adicionando ao explorados.
                borda.push(estado);
            }
        }
    }
    cout << endl;
}
