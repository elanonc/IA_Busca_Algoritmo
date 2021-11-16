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
    void buscaEmLargura(int raiz, int objetivo);
    void buscaEmLargura2(int raiz, int objetivo);

    int getTam()
    {
        return tam;
    }
    /*
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
    }*/
};

#endif