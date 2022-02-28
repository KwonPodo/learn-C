#ifndef ___GRAPH
#define ___GRAPH

#include <stdio.h>
#include <stdbool.h>
#define MAX 30

// Weight Graph Configuration - Adjacent Matrix
struct tagGraph
{
    int vertexCnt;
    int edgeCnt;
    int adjmatrix[MAX][MAX];

    int check[MAX];
}graph;

int name2int(char);

char int2name(int);

void initCheck();

void initGraph(FILE *fp);

void printGraph();

#endif