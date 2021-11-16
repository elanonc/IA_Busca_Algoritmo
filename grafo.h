#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>
#include <string>
#include "arvore.h"

using namespace std;

class Grafo
{

private:
    int tam;
    vector<list<pair<double, int>>> listaAdj;

public:
    Grafo(int V); // Construtor
    ~Grafo();
    void adicionar(int cidade1, int cidade2, double peso);
    void imprimirGrafo(int nVertice);
    void buscaEmLargura(int raiz, int objetivo);
    void buscaEmLargura2(int raiz, int objetivo);

    int getTam()
    {
        return tam;
    }

    vector<list<pair<double, int>>> *getListaAdj()
    {
        return &listaAdj;
    }

    void setTam(int tam)
    {
        this->tam = tam;
    }

    void setListaAdj(vector<list<pair<double, int>>> listaAdj)
    {
        this->listaAdj = listaAdj;
    }
};

#endif