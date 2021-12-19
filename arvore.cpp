#include "arvore.h"

// Construtor.
Arvore::Arvore()
{
    raiz = nullptr;
};

// Inserir raiz da arvore.
No *Arvore::inserir(int estado, string nome)
{
    if (raiz == nullptr)                    // verifica se a árvore está vazia
        return raiz = new No(estado, nome); // cria um novo nó
    else
        return raiz;
}

// Inserir raiz da arvore.
No *Arvore::inserir(int estado, string nome, double estimativa)
{
    if (raiz == nullptr)
    {                                            // verifica se a árvore está vazia
        raiz = new No(estado, nome, estimativa); // cria um novo nó
        return raiz;
    }
    else
        return raiz;
}

// Inserir um novo nó.
No *Arvore::inserirNo(No *no, int estado, string nome, double custo)
{
    No *novo_no = nullptr;
    if (no != nullptr && estado >= 0)
    {
        novo_no = new No(estado, nome, custo, no); // Criando um novo nó.
    }
    return novo_no;
}

// Inserir um novo nó.
No *Arvore::inserirNo(No *no, int estado, string nome, double custo, double estimativa)
{
    No *novo_no = nullptr;
    if (no != nullptr && estado >= 0)
    {
        novo_no = new No(estado, nome, custo, estimativa, no); // Criando um novo nó.
        return novo_no;
    }
    return novo_no;
}

// Imprimir todos os nós da arvore com seu custo de caminho, inciando da raiz.
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
        cout << no->getEstado() << " " << no->getNome() << ", custo real do caminho: " << no->getCustoDoCaminho() << endl;
    }
}

// Imprimir todos os nós da arvore com seu custo de caminho, inciando de um filho.
void Arvore::imprimirInvertido(No *no)
{
    while (no != nullptr)
    {
        cout << no->getEstado() << " " << no->getNome() << ", custo real do caminho: " << no->getCustoDoCaminho() << endl;
        no = no->getPai();
    }
}

// Imprimir todos os nós da arvore com seu custo de caminho e estimativa, inciando da raiz.
void Arvore::imprimirComEstimativa(No *no)
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
        cout << no->getEstado() << " " << no->getNome() << ", custo real do caminho: " << no->getCustoDoCaminho()
             << ", custo estimado do caminho: " << no->getEstimativa() << endl;
    }
}

// Imprimir todos os nós da arvore com seu custo de caminho e estimativa, inciando de um filho.
void Arvore::imprimirInvertidoComEstimativa(No *no)
{
    while (no != nullptr)
    {
        cout << no->getEstado() << " " << no->getNome() << ", custo real do caminho: " << no->getCustoDoCaminho()
             << ", custo estimado do caminho: " << no->getEstimativa() << endl;
        no = no->getPai();
    }
}