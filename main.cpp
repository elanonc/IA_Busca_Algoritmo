#include <iostream>
#include <vector>
#include "grafo.h"
// MAPEAMENTO DAS CIDADES

#define Arad 0
#define Zerind 1
#define Sibiu 2
#define Timisoare 3
#define Oradea 4
#define Fagaras 5
#define RimnicuVilcea 6
#define Lugej 7
#define Bucharest 8
#define Pitesti 9
#define Craiova 10
#define Mehadia 11
#define Drobeta 12
#define Giurglu 13
#define Urziceni 14
#define Vaslui 15
#define Mirsove 16
#define Lasi 17
#define Neamt 18
#define Eforie 19

using namespace std;

int main()
{
    int nVertice = 20; // numero de vertices
    Grafo g(nVertice);
    g.adicionar("Arad", "Zerind", Arad, Zerind, 75);
    g.adicionar("Arad", "Sibiu", Arad, Sibiu, 140);
    g.adicionar("Arad", "Timisoare", Arad, Timisoare, 118);
    g.adicionar("Zerind", "Oradea", Zerind, Oradea, 71);
    g.adicionar("Sibiu", "Fagaras", Sibiu, Fagaras, 90);
    g.adicionar("Sibiu", "RimnicuVilcea", Sibiu, RimnicuVilcea, 80);
    g.adicionar("Timisoare", "Lugej", Timisoare, Lugej, 111);
    g.adicionar("Oradea", "Sibiu", Oradea, Sibiu, 151);
    g.adicionar("Fagaras", "Bucharest", Fagaras, Bucharest, 211);
    g.adicionar("RimnicuVilcea", "Pitesti", RimnicuVilcea, Pitesti, 97);
    g.adicionar("RimnicuVilcea", "Craiova", RimnicuVilcea, Craiova, 146);
    g.adicionar("Lugej", "Mehadia", Lugej, Mehadia, 70);
    g.adicionar("Bucharest", "Giurglu", Bucharest, Giurglu, 90);
    g.adicionar("Bucharest", "Urziceni", Bucharest, Urziceni, 85);
    g.adicionar("Pitesti", "Bucharest", Pitesti, Bucharest, 101);
    g.adicionar("Craiova", "Pitesti", Craiova, Pitesti, 138);
    g.adicionar("Mehadia", "Drobeta", Mehadia, Drobeta, 75);
    g.adicionar("Drobeta", "Craiova", Drobeta, Craiova, 120);
    g.adicionar("Urziceni", "Vaslui", Urziceni, Vaslui, 142);
    g.adicionar("Urziceni", "Mirsove", Urziceni, Mirsove, 98);
    g.adicionar("Mirsove", "Eforie", Mirsove, Eforie, 86);
    g.adicionar("Vaslui", "lasi", Vaslui, Lasi, 92);
    g.adicionar("lasi", "Neamt", Lasi, Neamt, 97);
    g.imprimirGrafo(nVertice);
    cout << "--------------------------------" << endl;
    g.buscaEmLargura(Arad, Zerind);
    cout << "--------------------------------" << endl;
    g.buscaDeCustoUniforme(Arad, Zerind);
    cout << "--------------------------------" << endl;
    g.buscaEmProfundidade(Arad, Zerind);
    cout << "--------------------------------" << endl;
    return 0;
}
