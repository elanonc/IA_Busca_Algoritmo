#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#include <iostream>
#include <vector>
#include "grafo.h"
#include <map>
#include <string>

// MAPEAMENTO DAS CIDADES

#define Arad 0
#define Zerind 1
#define Sibiu 2
#define Timisoara 3
#define Oradea 4
#define Fagaras 5
#define RimnicuVilcea 6
#define Lugoj 7
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

map<string, int> valoresHeuristicos =
    {{
         "Arad",
         366,

     },
     {
         "Zerid",
         374,

     },
     {
         "Sibiu",
         253,

     },
     {
         "Timisoara",
         329,

     },
     {
         "Oradea",
         380,

     },
     {
         "Fagaras",
         176,

     },
     {
         "RimnicuVilcea",
         193,

     },
     {
         "Lugoj",
         244,

     },
     {
         "Bucharest",
         0,

     },
     {
         "Pitesti",
         100,

     },
     {
         "Craiova",
         160,

     },
     {
         "Mehadia",
         241,

     },
     {
         "Drobeta",
         242,

     },
     {
         "Giurgiu",
         77,

     },
     {
         "Urziceni ",
         80,

     },
     {
         "Vaslui",
         199,

     },
     {
         "Hirsova",
         151,

     },
     {
         "Iasi",
         226,

     },
     {
         "Neamt",
         234,

     },
     {
         "Eforie",
         161,
     }};

#endif