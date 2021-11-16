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

    int getEstado()
    {
        return estado;
    }

    // funções getters e setters

    No *getPai()
    {
        return pai;
    }

    void setEstado(int estado)
    {
        this->estado = estado;
    }

    void setPai(No *pai)
    {
        pai = pai;
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
    void imprimir(No *no);
};

#endif