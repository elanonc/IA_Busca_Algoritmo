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

int Grafo::buscarPorNome(string val)
{
    for (VerticeGrafo *v : listaAdj)
    {
        if (v->vertice == val)
            return v->valor;
    }
    return -1;
}

void Grafo::imprimirGrafo(int nVertice)
{

    for (int i = 0; i < nVertice; i++)
    {
        cout << listaAdj[i]->valor << " " << listaAdj[i]->vertice << ": ";

        for (pair<int, double> v : listaAdj[i]->vizinhos)
        {
            cout << "[" << v.first << ", " << v.second << " km]";
        }
        cout << endl;
    }
}

bool Grafo::estaNaFila(queue<No *> fila, int val)
{
    No *valor;
    while (!fila.empty())
    {
        valor = fila.front();
        if (valor->getEstado() == val)
        {
            return true;
        }
        fila.pop();
    }
    return false;
}

bool Grafo::estaNaFila(priority_queue<No *> fila, int val)
{

    while (!fila.empty())
    {
        if (fila.top()->getEstado() == val)
        {
            return true;
        }
        fila.pop();
    }
    return false;
}

bool Grafo::estaNaFilaComMaiorCusto(priority_queue<No *> *fila, No *val)
{
    No *valor;
    int tam = fila->size();
    bool rt = false;
    for (int i = 0; i < tam; i++)
    {

        valor = fila->top();
        if (valor->getEstado() == val->getEstado())
        {
            if (val->getCustoDoCaminho() < valor->getCustoDoCaminho() && !rt)
            {
                valor = val;
                rt = true;
            }
        }
        fila->pop();
        fila->push(valor);
    }
    return rt;
}

bool Grafo::estaNaPilha(stack<No *> pilha, int val)
{
    while (!pilha.empty())
    {
        if (pilha.top()->getEstado() == val)
        {
            return true;
        }
        pilha.pop();
    }
    return false;
}

void Grafo::buscaEmLargura(int raiz, int objetivo)
{
    Arvore arvore;
    No *no;
    queue<No *> borda; // É uma fila.
    no = arvore.inserir(raiz, listaAdj[raiz]->vertice);
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
            No *filho = arvore.inserirNo(no, estado, listaAdj[estado]->vertice, v.second);
            if (!explorados[filho->getEstado()] || estaNaFila(borda, filho->getEstado()))
            {
                if (filho->getEstado() == objetivo)
                {
                    arvore.imprimir(filho);
                    return;
                }
                borda.push(filho);
            }
        }
    }
    delete explorados;
    return;
}

void Grafo::buscaDeCustoUniforme(int raiz, int objetivo)
{
    Arvore arvore;
    No *no;
    priority_queue<No *> borda; // É uma fila.
    no = arvore.inserir(raiz, listaAdj[raiz]->vertice);
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    int estado;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    borda.push(arvore.getRaiz()); // iniciando a borda.

    while (!borda.empty())
    {

        no = borda.top();                // remover elemento da borda.
        borda.pop();                     // retirando o que está a mais tempo na fila.
        if (no->getEstado() == objetivo) // Retorna a solção.
        {
            arvore.imprimir(no);
            return;
        }
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.

        // para cada ação aplicável em nó.estado
        list<pair<int, double>> lista = listaAdj[no->getEstado()]->vizinhos;
        for (pair<int, double> v : lista)
        {
            estado = v.first;                                                              // Cidade vizinha.
            No *filho = arvore.inserirNo(no, estado, listaAdj[estado]->vertice, v.second); // Criando um filho.
            if (!explorados[filho->getEstado()] || estaNaFila(borda, filho->getEstado()))
            {
                borda.push(filho);
            }
            else
            {
                estaNaFilaComMaiorCusto(&borda, filho);
            }
        }
    }
    delete explorados;
    return;
}

void Grafo::buscaEmProfundidade(int raiz, int objetivo)
{
    Arvore arvore;
    No *no;
    stack<No *> borda; // É uma fila.
    no = arvore.inserir(raiz, listaAdj[raiz]->vertice);
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    int estado;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    borda.push(arvore.getRaiz()); // iniciando a borda.

    while (!borda.empty())
    {

        no = borda.top();                   // remover elemento da borda.
        borda.pop();                        // retirando o que está a mais tempo na fila.
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.

        // para cada ação aplicável em nó.estado
        list<pair<int, double>> lista = listaAdj[no->getEstado()]->vizinhos;
        for (pair<int, double> v : lista)
        {
            estado = v.first; // Cidade vizinha.
            No *filho = arvore.inserirNo(no, estado, listaAdj[estado]->vertice, v.second);
            if (!explorados[filho->getEstado()] || estaNaPilha(borda, filho->getEstado()))
            {
                if (filho->getEstado() == objetivo)
                {
                    arvore.imprimir(filho);
                    return;
                }
                borda.push(filho);
            }
        }
    }
    delete explorados;
    return;
}

// Falta terminar

void Grafo::buscaGulosa(int raiz, int objetivo, int valoresHeuristicos[])
{
    Arvore arvore;
    No *no;
    priority_queue<No *> borda; // É uma fila.
    no = arvore.inserir(raiz, listaAdj[raiz]->vertice);
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    int estado;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    borda.push(arvore.getRaiz()); // iniciando a borda.

    while (!borda.empty())
    {

        no = borda.top();                // remover elemento da borda.
        borda.pop();                     // retirando o que está a mais tempo na fila.
        if (no->getEstado() == objetivo) // Retorna a solção.
        {
            arvore.imprimir(no);
            return;
        }
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.

        // para cada ação aplicável em nó.estado
        list<pair<int, double>> lista = listaAdj[no->getEstado()]->vizinhos;
        for (pair<int, double> v : lista)
        {
            estado = v.first;                                                              // Cidade vizinha.
            No *filho = arvore.inserirNo(no, estado, listaAdj[estado]->vertice, v.second); // Criando um filho.
            if (!explorados[filho->getEstado()] || estaNaFila(borda, filho->getEstado()))
            {
                borda.push(filho);
            }
            else
            {
                estaNaFilaComMaiorCusto(&borda, filho);
            }
        }
    }
    delete explorados;
    return;
}

void Grafo::buscaAEstrela(int raiz, int objetivo, int valoresHeuristicos[])
{
    Arvore arvore;
    No *no;
    priority_queue<No *> borda; // É uma fila.
    no = arvore.inserir(raiz, listaAdj[raiz]->vertice);
    bool *explorados = new bool[tam]; // Cidades já visitadas.
    int estado;

    for (int i = 1; i < tam; i++) // Colocando todas as cidades como não exploradas.
        explorados[i] = false;

    borda.push(arvore.getRaiz()); // iniciando a borda.

    while (!borda.empty())
    {

        no = borda.top();                // remover elemento da borda.
        borda.pop();                     // retirando o que está a mais tempo na fila.
        if (no->getEstado() == objetivo) // Retorna a solção.
        {
            arvore.imprimir(no);
            return;
        }
        explorados[no->getEstado()] = true; // Colocando a raiz como explorada.

        // para cada ação aplicável em nó.estado
        list<pair<int, double>> lista = listaAdj[no->getEstado()]->vizinhos;
        for (pair<int, double> v : lista)
        {
            estado = v.first;                                                              // Cidade vizinha.
            No *filho = arvore.inserirNo(no, estado, listaAdj[estado]->vertice, v.second); // Criando um filho.
            if (!explorados[filho->getEstado()] || estaNaFila(borda, filho->getEstado()))
            {
                borda.push(filho);
            }
            else
            {
                estaNaFilaComMaiorCusto(&borda, filho);
            }
        }
    }
    delete explorados;
    return;
}