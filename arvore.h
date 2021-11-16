#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>
#include <string>

using namespace std;

class No
{

private:
    int estado;
    No *pai;
    int custoDoCaminho;

public:
    No(int estado)
    {
        this->estado = estado;
        pai = nullptr;
        custoDoCaminho = 0;
    };

    // funções getters e setters

    int getEstado()
    {
        return estado;
    }

    int getCustoDoCaminho()
    {
        return custoDoCaminho;
    }

    No *getPai()
    {
        return pai;
    }

    void setEstado(int estado)
    {
        this->estado = estado;
    }

    void setCustoDoCaminho(int custoDoCaminho)
    {
        this->custoDoCaminho = custoDoCaminho;
    }

    void setPai(No *pai)
    {
        this->pai = pai;
    }
};

class Arvore
{

private:
    No *raiz;

public:
    Arvore();
    No *inserir(int estado);
    No *inserirNo(No *no, int estado);
    No *getRaiz()
    {
        return raiz;
    }
    void ajeitarCustoDoNo(No *no);
    void imprimir(No *no);
};

#endif