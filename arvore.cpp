#include "arvore.h"

Arvore::Arvore()
{
    raiz = nullptr;
};

No *Arvore::inserir(int estado, string nome)
{
    if (raiz == nullptr)                    // verifica se a árvore está vazia
        return raiz = new No(estado, nome); // cria um novo nó
    else
        return raiz;
}

No *Arvore::inserir(int estado, string nome, double estimativa)
{
    if (raiz == nullptr)
    {                                // verifica se a árvore está vazia
        raiz = new No(estado, nome); // cria um novo nó
        raiz->setEstimativa(estimativa);
        return raiz;
    }
    else
        return raiz;
}

No *Arvore::inserirNo(No *no, int estado, string nome, double custo)
{
    if (no != nullptr && estado >= 0)
    {
        No *novo_no = new No(estado, nome); // Criando um novo nó.
        novo_no->setPai(no);                // Adicionando o pai ao filho.
        novo_no->setCustoDoCaminho(custo);
        return novo_no;
    }
}

No *Arvore::inserirNo(No *no, int estado, string nome, double custo, double estimativa)
{
    if (no != nullptr && estado >= 0)
    {
        No *novo_no = new No(estado, nome); // Criando um novo nó.
        novo_no->setPai(no);                // Adicionando o pai ao filho.
        novo_no->setCustoDoCaminho(custo);
        novo_no->setEstimativa(estimativa);
        return novo_no;
    }
}

void Arvore::imprimir(No *no)
{
    stack<No *> pilha;
    while (no != nullptr)
    {
        pilha.push(no);
        no = no->getPai();
    }
    while (!pilha.empty())
    {
        no = pilha.top();
        pilha.pop();
        cout << no->getEstado() << " " << no->getNome() << " custo: " << no->getCustoDoCaminho() << endl;
    }
}

void Arvore::imprimirInvertido(No *no)
{
    while (no != nullptr)
    {
        cout << no->getEstado() << " " << no->getNome() << " custo: " << no->getCustoDoCaminho() << endl;
        no = no->getPai();
    }
}