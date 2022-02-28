#ifndef ___GRAPH
#define ___GRAPH

#define MAX 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Weight Graph Configuration - Adjacent Matrix
struct tagGraph
{
    int vertexCnt;
    int edgeCnt;
    int adjmatrix[MAX][MAX];

    bool check[MAX];
}graph;

int name2int(char ch);

char int2name(int i);

void initCheck();

void initGraph(FILE*);

void printGraph();

#endif