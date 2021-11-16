#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>

using namespace std;

class Grafo
{
    int tam;
    vector<list<pair<double, int>>> listaAdj;

public:
    Grafo(int V); // Construtor
    ~Grafo();
    void adicionar(int cidade1, int cidade2, double peso);
    void imprimirGrafo(int nVertice);
    void buscaEmLargura(int raiz, int objetivo);
    struct No
    {
        No *pai;
    };
    typedef pair<double, No *> caminho;
};

#endif