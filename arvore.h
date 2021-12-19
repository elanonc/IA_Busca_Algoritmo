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

// Estrutura Nó
class No
{

private:
    string nome;           // Nome que o nó corresponde.
    int estado;            // O estado a que o nó corresponde.
    double custoDoCaminho; // O custo de sair do estado inicial e alcançar o nó.
    double estimativa;     // O custo de sair do estado inicial e alcançar o nó por uma estimativa.
    No *pai;               // o nó na árvore que gerou esse nó.

public:
    // Construtor
    No(int estado, string nome)
    {
        this->estado = estado;
        this->nome = nome;
        pai = nullptr;
        custoDoCaminho = 0;
        estimativa = 0;
    };
    // Construtor
    No(int estado, string nome, double estimativa)
    {
        this->estado = estado;
        this->nome = nome;
        custoDoCaminho = 0;
        pai = nullptr;
        this->estimativa = estimativa;
    };
    // Construtor
    No(int estado, string nome, double custoDoCaminho, No *pai)
    {
        this->estado = estado;
        this->nome = nome;
        this->custoDoCaminho = custoDoCaminho;
        this->pai = pai;
    };
    // Construtor
    No(int estado, string nome, double custoDoCaminho, double estimativa, No *pai)
    {
        this->estado = estado;
        this->nome = nome;
        this->pai = nullptr;
        this->custoDoCaminho = custoDoCaminho;
        this->estimativa = estimativa;
        this->pai = pai;
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
    void imprimirComEstimativa(No *no);
    void imprimirInvertidoComEstimativa(No *no);
};

#endif