#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>

#define TAMANHO 100

using namespace std;

class Grafo
{
public:
    
    void adicionar(int cidade1, int cidade2, double peso);
    void imprimirGrafo(int nVertice);
    void buscaEmLargura();
};

#endif