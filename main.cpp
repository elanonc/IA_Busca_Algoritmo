#include <iostream>
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
#define Dobreta 12
#define Giurglu 13
#define Urziceni 14
#define Vaslui 15
#define Mirsove 16
#define lasi 17
#define Neamt 18
#define Eforie 19

using namespace std;

int main()
{
    int nVertice = 20; // numero de vertices
    Grafo g(nVertice);
    g.adicionar(Arad, Zerind, 75);
    g.adicionar(Arad, Sibiu, 140);
    g.adicionar(Arad, Timisoare, 118);
    g.adicionar(Zerind, Oradea, 71);
    g.adicionar(Sibiu, Fagaras, 90);
    g.adicionar(Sibiu, RimnicuVilcea, 80);
    g.adicionar(Timisoare, Lugej, 111);
    g.adicionar(Oradea, Sibiu, 151);
    g.adicionar(Fagaras, Bucharest, 211);
    g.adicionar(RimnicuVilcea, Pitesti, 97);
    g.adicionar(RimnicuVilcea, Craiova, 146);
    g.adicionar(Lugej, Mehadia, 70);
    g.adicionar(Bucharest, Giurglu, 90);
    g.adicionar(Bucharest, Urziceni, 85);
    g.adicionar(Pitesti, Bucharest, 101);
    g.adicionar(Craiova, Pitesti, 138);
    g.adicionar(Mehadia, Dobreta, 75);
    g.adicionar(Dobreta, Craiova, 120);
    g.adicionar(Urziceni, Vaslui, 142);
    g.adicionar(Urziceni, Mirsove, 98);
    g.adicionar(Mirsove, Eforie, 86);
    g.adicionar(Vaslui, lasi, 92);
    g.adicionar(lasi, Neamt, 97);
    g.imprimirGrafo(nVertice);
    g.buscaEmLargura(lasi, Neamt);
    return 0;
}
