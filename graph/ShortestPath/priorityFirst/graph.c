#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int name2int(char name)
{
    return name - 'a';
}

char int2name(int i)
{
    return i + 'a';
}

void initCheck()
{
    memset(graph.check, 0, sizeof(graph.check));
}

void initGraph(FILE *fp)
{
    int i, weight;
    int vcnt, ecnt;
    int v1, v2;
    char c1, c2;

    // initiate adjmatrix, check
    memset(graph.adjmatrix, 0, sizeof(graph.adjmatrix));
    memset(graph.check, 0, sizeof(graph.check));

    printf("Enter number of Vertices and Edges\n"); 
    fscanf(fp, "%d%d", &vcnt, &ecnt);

    // printf("vcnt: %d\necnt: %d\n", vcnt, ecnt);

    graph.vertexCnt = vcnt;
    graph.edgeCnt = ecnt;

    for (i = 0; i < ecnt; i++)
    {
        printf("Enter two vertices that consists an edge\n");
        fscanf(fp, " %c %c", &c1, &c2);
        printf("c1: %c, c2: %c\n\n", c1, c2);

        printf("Enter weight of the given edge\n");
        fscanf(fp, "%d", &weight);
        printf("weight: %d\n\n", weight);

        v1 = name2int(c1);
        v2 = name2int(c2);

        graph.adjmatrix[v1][v2] = weight;
        graph.adjmatrix[v2][v1] = weight;
    }

    for (i = 0; i < graph.vertexCnt; i++)
        graph.adjmatrix[i][i] = 0;
    
    for (i = 0; i < MAX; i++)
        graph.check[i] = false;
}

void printGraph()
{
    int i, j;

    for (i = 0; i < graph.vertexCnt; i++)
    {
        printf("matrix[%2d] : ", i);
        for (j = 0; j < graph.vertexCnt; j++)
        {
            printf("%d ", graph.adjmatrix[i][j]);
        }
        puts("");
    }
    puts("\n");
}