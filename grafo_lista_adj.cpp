/*
MAPEAMENTO DAS CIDADES
0 - Oradea
1 - Zerind
2 - Arad
3 - Sibiu
4 - Fagaras
5 - Timisoara
6 - Rimnicu Vilcea
7 - Lugoj
8 - Pitesti
9 - Mehadia
10 - Drobeta
11 - Craiova
12 - Giurgiu
13 - Eforie
14 - Bucharest
15 - Urziceni
16 - Hirsova
17 - Vaslui
18 - Iasi
19 - Neamt
*/

#include "graph.h"
#include <iostream>
#include <list>
#include <utility> // pair
#include <vector>

using namespace std;

void printaGrafo(vector<list<pair<int, int>>> listaAdj, int nVertice)
{
    for (int i = 0; i < nVertice; i++)
    {
        cout << i << ": ";
        for (auto j : listaAdj[i])
        {
            cout << "[" << j.first << " " << j.second << "km] ";
        }
        cout << endl;
        cout << endl;
    }
}

vector<list<pair<int, int>>> constroiGrafo(int nVertice)
{
    vector<list<pair<int, int>>> listaAdj(nVertice);

    listaAdj[0].push_back(make_pair(1, 71)); // Oradea - Zerind
    listaAdj[0].push_back(make_pair(3, 151)); // Oradea - Sibiu

    listaAdj[1].push_back(make_pair(0, 71)); // Zerind - Oradea
    listaAdj[1].push_back(make_pair(2, 75)); // Zerind - Arad

    listaAdj[2].push_back(make_pair(1, 75)); // Arad - Zerind
    listaAdj[2].push_back(make_pair(3, 140)); // Arad - Sibiu
    listaAdj[2].push_back(make_pair(5, 118)); // Arad - Timisoara

    listaAdj[3].push_back(make_pair(0, 151)); // Sibiu - Oradea
    listaAdj[3].push_back(make_pair(2, 140)); // Sibiu - Arad
    listaAdj[3].push_back(make_pair(4, 99)); // Sibiu - Fagaras
    listaAdj[3].push_back(make_pair(6, 80)); // Sibiu - Rimnicu Vilcea

    listaAdj[4].push_back(make_pair(3, 99));  // Fagaras - Sibiu
    listaAdj[4].push_back(make_pair(14, 211)); // Fagaras - Bucharest

    listaAdj[5].push_back(make_pair(2, 118)); // Timisoara - Arad
    listaAdj[5].push_back(make_pair(7, 111)); // Timisoara - Lugoj

    listaAdj[6].push_back(make_pair(3, 80));  // Rimnicu Vilcea - Sibiu
    listaAdj[6].push_back(make_pair(11, 146)); // Rimnicu Vilcea - Craiova
    listaAdj[6].push_back(make_pair(8, 97));  // Rimnicu Vilcea - Pitesti

    listaAdj[7].push_back(make_pair(5, 111)); // Lugoj - Timisoara
    listaAdj[7].push_back(make_pair(9, 70)); // Lugoj - Mehadia

    listaAdj[8].push_back(make_pair(6, 97));  // Pitesti - Rimnicu Vilcea
    listaAdj[8].push_back(make_pair(11, 138)); // Pitesti - Craiova
    listaAdj[8].push_back(make_pair(14, 101)); // Pitesti - Bucharest

    listaAdj[9].push_back(make_pair(7, 70));  // Mehadia - Lugoj
    listaAdj[9].push_back(make_pair(10, 75)); // Mehadia - Drobeta

    listaAdj[10].push_back(make_pair(9, 75));  // Drobeta - Mehadia
    listaAdj[10].push_back(make_pair(11, 120)); // Drobeta - Craiova

    listaAdj[11].push_back(make_pair(10, 120)); // Craiova - Drobeta
    listaAdj[11].push_back(make_pair(6, 146));  // Craiova - Rimnicu Vilcea
    listaAdj[11].push_back(make_pair(8, 138));  // Craiova - Pitesti

    listaAdj[12].push_back(make_pair(14, 90)); // Giurgiu - Bucharest

    listaAdj[13].push_back(make_pair(16, 86)); // Eforie - Hirsova

    listaAdj[14].push_back(make_pair(4, 211));  // Bucharest - Fagaras
    listaAdj[14].push_back(make_pair(8, 101));  // Bucharest - Pitesti
    listaAdj[14].push_back(make_pair(12, 90)); // Bucharest - Giurgiu
    listaAdj[14].push_back(make_pair(15, 85)); // Bucharest - Urziceni

    listaAdj[15].push_back(make_pair(14, 85)); // Urziceni - Bucharest
    listaAdj[15].push_back(make_pair(16, 98)); // Urziceni - Hirsova
    listaAdj[15].push_back(make_pair(17, 142)); // Urziceni - Vaslui

    listaAdj[16].push_back(make_pair(15, 98)); // Hirsova - Urziceni
    listaAdj[16].push_back(make_pair(13, 86)); // Hirsova - Eforie

    listaAdj[17].push_back(make_pair(15, 142)); // Vaslui - Urziceni
    listaAdj[17].push_back(make_pair(18, 92)); // Vaslui - Iasi

    listaAdj[18].push_back(make_pair(17, 92)); // Iasi - Vaslui
    listaAdj[18].push_back(make_pair(19, 87)); // Iasi - Neamt

    listaAdj[19].push_back(make_pair(18, 87)); // Neamt - Iasi
    return listaAdj;
}

int main()
{
    int nVertice = 20;                               // numero de vertices
    vector<list<pair<int, int>>> listaAdj(nVertice); // grafo representado por uma lista de adjacencia, primeiro elemento do par é a cidade e o segundo a distancia
    listaAdj = constroiGrafo(nVertice);
    printaGrafo(listaAdj, nVertice);
}
