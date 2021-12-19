#include "variaveis.h"

int main()
{
    int nVertice = 20; // numero de vertices
    Grafo g(nVertice);
    string origem;
    g.adicionar("Arad", "Zerind", Arad, Zerind, 75);
    g.adicionar("Arad", "Sibiu", Arad, Sibiu, 140);
    g.adicionar("Arad", "Timisoara", Arad, Timisoara, 118);
    g.adicionar("Zerind", "Oradea", Zerind, Oradea, 71);
    g.adicionar("Sibiu", "Fagaras", Sibiu, Fagaras, 99);
    g.adicionar("Sibiu", "RimnicuVilcea", Sibiu, RimnicuVilcea, 80);
    g.adicionar("Timisoara", "Lugoj", Timisoara, Lugoj, 111);
    g.adicionar("Oradea", "Sibiu", Oradea, Sibiu, 151);
    g.adicionar("Fagaras", "Bucharest", Fagaras, Bucharest, 211);
    g.adicionar("RimnicuVilcea", "Pitesti", RimnicuVilcea, Pitesti, 97);
    g.adicionar("RimnicuVilcea", "Craiova", RimnicuVilcea, Craiova, 146);
    g.adicionar("Lugoj", "Mehadia", Lugoj, Mehadia, 70);
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
    g.adicionar("Iasi", "Neamt", Iasi, Neamt, 87);
    cout << endl;
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
        cout << endl;
        cout << "--------------Em Largura------------------" << endl;
        g.buscaEmLargura(result, Bucharest);
        cout << endl;
        cout << "--------------Custo Uniforme--------------" << endl;
        g.buscaDeCustoUniforme(result, Bucharest);
        cout << endl;
        cout << "--------------Em Profundidade-------------" << endl;
        g.buscaEmProfundidade(result, Bucharest);
        cout << endl;
        cout << "--------------Gulosa----------------------" << endl;
        g.buscaGulosa(result, Bucharest, valoresHeuristicos);
        cout << endl;
        cout << "--------------A*--------------------------" << endl;
        g.buscaAEstrela(result, Bucharest, valoresHeuristicos);
        cout << "--------------------------------" << endl;
        cout << endl;
    }
    return 0;
}