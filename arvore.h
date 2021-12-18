#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class No
{

private:
    string nome;
    int estado;
    double custoDoCaminho;
    double estimativa;
    No *pai;

public:
    No(int estado, string nome)
    {
        this->nome = nome;
        this->estado = estado;
        pai = nullptr;
        custoDoCaminho = 0;
    };

    // funções getters e setters

    string getNome()
    {
        return nome;
    }

    int getEstado()
    {
        return estado;
    }

    double getCustoDoCaminho()
    {
        return custoDoCaminho;
    }

    double getEstimativa()
    {
        return estimativa;
    }

    No *getPai()
    {
        return pai;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    void setEstado(int estado)
    {
        this->estado = estado;
    }

    void setCustoDoCaminho(double custoDoCaminho)
    {
        this->custoDoCaminho = custoDoCaminho;
    }

    void setEstimativa(double estimativa)
    {
        this->estimativa = estimativa;
    }

    void setPai(No *pai)
    {
        this->pai = pai;
    }
};

struct porCusto
{
    bool operator()(No *no1, No *no2)
    {
        return no1->getCustoDoCaminho() > no2->getCustoDoCaminho();
    }
};

struct porEstimativa
{
    bool operator()(No *no1, No *no2)
    {
        return no1->getEstimativa() > no2->getEstimativa();
    }
};

class Arvore
{

private:
    No *raiz;

public:
    Arvore();
    No *inserir(int estado, string nome);
    No *inserir(int estado, string nome, double estimativa);
    No *inserirNo(No *no, int estado, string nome, double custo);
    No *inserirNo(No *no, int estado, string nome, double custo, double estimativa);
    No *getRaiz()
    {
        return raiz;
    }
    void imprimir(No *no);
    void imprimirInvertido(No *no);
};

#endif