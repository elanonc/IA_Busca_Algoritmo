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
    No *novo_no = new No(estado); // Criando um novo nó.
    novo_no->setPai(no);          // Adicionando o pai ao filho.
    return novo_no;
}

void Arvore::imprimir(No *no)
{
    while (no->getPai() != nullptr)
    {
        cout << no->getEstado() << endl;
        no = no->getPai();
    }
}