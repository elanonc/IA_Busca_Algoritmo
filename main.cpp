#include <iostream>
#include <vector>
#include "grafo.h"
#include <string>
// MAPEAMENTO DAS CIDADES

#define Arad 0
#define Zerind 1
#define Sibiu 2
#define Timisoara 3
#define Oradea 4
#define Fagaras 5
#define RimnicuVilcea 6
#define Lugej 7
#define Bucharest 8
#define Pitesti 9
#define Craiova 10
#define Mehadia 11
#define Drobeta 12
#define Giurgiu 13
#define Urziceni 14
#define Vaslui 15
#define Hirsova 16
#define Iasi 17
#define Neamt 18
#define Eforie 19

using namespace std;

int main()
{
    int nVertice = 20; // numero de vertices
    Grafo g(nVertice);
    string origem;
    g.adicionar("Arad", "Zerind", Arad, Zerind, 75);
    g.adicionar("Arad", "Sibiu", Arad, Sibiu, 140);
    g.adicionar("Arad", "Timisoara", Arad, Timisoara, 118);
    g.adicionar("Zerind", "Oradea", Zerind, Oradea, 71);
    g.adicionar("Sibiu", "Fagaras", Sibiu, Fagaras, 90);
    g.adicionar("Sibiu", "RimnicuVilcea", Sibiu, RimnicuVilcea, 80);
    g.adicionar("Timisoara", "Lugej", Timisoara, Lugej, 111);
    g.adicionar("Oradea", "Sibiu", Oradea, Sibiu, 151);
    g.adicionar("Fagaras", "Bucharest", Fagaras, Bucharest, 211);
    g.adicionar("RimnicuVilcea", "Pitesti", RimnicuVilcea, Pitesti, 97);
    g.adicionar("RimnicuVilcea", "Craiova", RimnicuVilcea, Craiova, 146);
    g.adicionar("Lugej", "Mehadia", Lugej, Mehadia, 70);
    g.adicionar("Bucharest", "Giurgiu", Bucharest, Giurgiu, 90);
    g.adicionar("Bucharest", "Urziceni", Bucharest, Urziceni, 85);
    g.adicionar("Pitesti", "Bucharest", Pitesti, Bucharest, 101);
    g.adicionar("Craiova", "Pitesti", Craiova, Pitesti, 138);
    g.adicionar("Mehadia", "Drobeta", Mehadia, Drobeta, 75);
    g.adicionar("Drobeta", "Craiova", Drobeta, Craiova, 120);
    g.adicionar("Urziceni", "Vaslui", Urziceni, Vaslui, 142);
    g.adicionar("Urziceni", "Hirsova", Urziceni, Hirsova, 98);
    g.adicionar("Hirsova", "Eforie", Hirsova, Eforie, 86);
    g.adicionar("Vaslui", "Iasi", Vaslui, Iasi, 92);
    g.adicionar("Iasi", "Neamt", Iasi, Neamt, 97);
    g.imprimirGrafo(nVertice);
    cout << "Por favor, digite a cidade de origem" << endl;
    cin >> origem;
    int result = g.buscarPorNome(origem);
    if (result == -1)
        cout << "Valor inexistente" << endl;
    else if (result == 8)
        cout << "Erro, Bucharest já é o nosso destino" << endl;
    else
    {
        cout << "--------------------------------" << endl;
        g.buscaEmLargura(result, Bucharest);
        cout << "--------------------------------" << endl;
        g.buscaDeCustoUniforme(result, Bucharest);
        cout << "--------------------------------" << endl;
        g.buscaEmProfundidade(result, Bucharest);
        cout << "--------------------------------" << endl;
    }

    return 0;
}
