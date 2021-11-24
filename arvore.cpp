#include "arvore.h"

Arvore::Arvore()
{
    raiz = nullptr;
};

No *Arvore::inserir(int estado)
{
    if (raiz == nullptr)              // verifica se a árvore está vazia
        return raiz = new No(estado); // cria um novo nó
    else
        return inserirNo(raiz, estado);
}

No *Arvore::inserirNo(No *no, int estado)
{
    if (no != nullptr && estado >= 0)
    {
        No *novo_no = new No(estado); // Criando um novo nó.
        novo_no->setPai(no);          // Adicionando o pai ao filho.
        ajeitarCustoDoNo(no);
        return novo_no;
    }
}

void Arvore::imprimir(No *no)
{
    while (no != nullptr)
    {
        cout << no->getEstado() << " custo: " << no->getCustoDoCaminho() << endl;
        no = no->getPai();
    }
}

void Arvore::ajeitarCustoDoNo(No *no)
{
    while (no != nullptr)
    {
        no->setCustoDoCaminho((no->getCustoDoCaminho()) + 1);
        no = no->getPai();
    }
}