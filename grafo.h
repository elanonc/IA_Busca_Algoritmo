#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include "arvore.h"

using namespace std;

class VerticeGrafo
{
public:
    int valor;
    string vertice;

    list<pair<int, double>> vizinhos;
    VerticeGrafo(int valor, string vertice)
    {
        this->valor = valor;
        this->vertice = vertice;
    }

    void adicionarVizinho(int valor, double peso)
    {
        vizinhos.push_back(make_pair(valor, peso));
    }
};

class Grafo
{

private:
    int tam;
    vector<VerticeGrafo *> listaAdj; // Guarda os endereços dos vertices.

public:
    Grafo(int V); // Construtor
    ~Grafo();
    void adicionar(string vertice1, string vertice2, int valor1, int valor2, double peso);
    void imprimirGrafo(int nVertice);
    int buscarPorNome(string val);
    void buscaEmLargura(int raiz, int objetivo);
    void buscaDeCustoUniforme(int raiz, int objetivo);
    void buscaEmProfundidade(int raiz, int objetivo);
    void buscaGulosa(int raiz, int objetivo);
    void buscaAEstrela(int raiz, int objetivo);
    bool estaNaFila(queue<No *> fila, int val);
    bool estaNaFila(priority_queue<No *> fila, int val);
    bool estaNaFilaComMaiorCusto(priority_queue<No *> *fila, No *val);
    bool estaNaPilha(stack<No *> pilha, int val);

    int getTam()
    {
        return tam;
    }
};

#endif