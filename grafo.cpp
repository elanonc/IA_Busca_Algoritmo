#include <iostream>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int tam)
{
    this->tam = tam;
    listaAdj = vector<VerticeGrafo *>(tam);
    for (int i = 0; i < tam; i++)
    {
        listaAdj[i] = nullptr;
    }
}

Grafo::~Grafo()
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Delete " << listaAdj[i]->valor << endl;
        delete listaAdj[i];
    }
}

void Grafo::adicionar(string vertice1, string vertice2, int valor1, int valor2, double peso)
{
    VerticeGrafo *v1 = listaAdj[valor1], *v2 = listaAdj[valor2];
    if (v1 == nullptr)
    {
        v1 = new VerticeGrafo(valor1, vertice1);
        listaAdj[valor1] = v1;
    }

    if (v2 == nullptr)
    {
        v2 = new VerticeGrafo(valor2, vertice2);
        listaAdj[valor2] = v2;
    }

    v1->adicionarVizinho(valor2, peso);
    v2->adicionarVizinho(valor1, peso);
}

void Grafo::imprimirGrafo(int nVertice)
{

    for (int i = 0; i < nVertice; i++)
    {
        cout << listaAdj[i]->valor << " " << listaAdj[i]->vertice << ": ";

        for (pair<int, double> v : listaAdj[i]->vizinhos)
        {
            cout << "[" << v.first << "," << v.second << " km]";
        }
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

    while (!borda.empty())
    {

        no = borda.front();                 // remover elemento da borda.
        borda.pop();                        // retirando o que está a mais tempo na fila.
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.

        // para cada ação aplicável em nó.estado
        list<pair<int, double>> lista = listaAdj[no->getEstado()]->vizinhos;
        for (pair<int, double> v : lista)
        {
            estado = v.first; // Cidade vizinha.
            No *filho = arvore.inserirNo(no, estado);
            if (!explorados[filho->getEstado()] /*|| borda.front() != filho*/)
            {
                if (filho->getEstado() == objetivo)
                {
                    arvore.imprimir(filho);
                    return;
                }
            }
            borda.push(filho);
        }
    }
    return;
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
        list<pair<int, double>> lista = listaAdj[no]->vizinhos;
        for (pair<int, double> v : lista)
        {
            int estado = v.first; // Cidades vizinhas.
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
