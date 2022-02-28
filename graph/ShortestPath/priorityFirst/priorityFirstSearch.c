#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "graph.h"

FILE *fp;

struct path 
{
    char vertex;
    int accum_weight;
};

struct pq
{
    struct path *heap;
    int heapCnt;
};

struct path* createNode(char vertex, int weight)
{
    struct path *new = (struct path*)malloc(sizeof(struct path));
    new->vertex = vertex;
    new->accum_weight += weight;

    return new;
}

struct pq* initHeap()
{
    struct pq *q = (struct pq*)malloc(sizeof(struct pq));
    q->heap = (struct path*)malloc(graph.vertexCnt+1 * sizeof(struct path*));
    q->heap[0].accum_weight = 0;
    q->heap[0].vertex = 'R';
    q->heapCnt = 0;

    return q;
}

void terminHeap(struct pq *q)
{
    free(q->heap);
    free(q);
}

void printHeap(struct pq * q)
{
    int i = 1;
    while (i <= q->heapCnt)
    {
        printf("%c: %d\n", q->heap[i].vertex, q->heap[i].accum_weight);
        i++;
    }
    puts("");
}

void enque(struct pq * q, struct path *n)
{
    q->heapCnt++;
    int i = q->heapCnt;
    q->heap[i] = *n;
    while (q->heap[i/2].accum_weight > q->heap[i].accum_weight)
    {
        // swap
        struct path tmp = q->heap[i];
        q->heap[i] = q->heap[i/2];
        q->heap[i/2] = tmp;
    }
}

struct path deque(struct pq *q)
{
    struct path root = q->heap[1];
    q->heap[1] = q->heap[q->heapCnt];
    q->heapCnt--;

    int i = 1;
    // 내부 노드에 한해서
    while (i <= q->heapCnt/2)
    {
        int j = (q->heap[i*2].accum_weight < q->heap[i*2 + 1].accum_weight) ? i*2 : i*2 + 1;

        if (q->heap[i].accum_weight > q->heap[j].accum_weight)
        {
            // swap;
            struct path tmp = q->heap[i];
            q->heap[i] = q->heap[j];
            q->heap[j] = tmp;

            i = j;
        }
        else 
            break;
    }

    return root;
}

struct path* searchQ(struct pq *q, char v)
{
    int i;
    for (i = 1; i <= q->heapCnt; i++)
    {
        if (q->heap[i].vertex == v)
            return &q->heap[i];
    }

    return NULL;
}

void updateQ(struct path *s, int cmp_weight)
{
    if (s->accum_weight > cmp_weight)
        s->accum_weight = cmp_weight;
}

int PFS(char startVertex, char endVertex, struct pq *q)
{
    int i, j;
    int accum_cost[graph.vertexCnt];
    memset(accum_cost, 0, sizeof(accum_cost));

    enque(q, createNode(startVertex, 0));

    while (q->heapCnt > 0)
    {
        struct path pop = deque(q);
        i = name2int(pop.vertex);
        graph.check[i] = true;
        accum_cost[i] = pop.accum_weight;
        printf("Vertex : %c\tAccumulated Weight: %d\n", pop.vertex, pop.accum_weight);

        for (j = 0; j < graph.vertexCnt; j++)
        {
            if (graph.adjmatrix[i][j] && accum_cost[j] == 0)
            {
                struct path *s = searchQ(q, int2name(j));
                // if the path to an adj vertex is not in the priority queue
                if (s == NULL)
                    enque(q, createNode(int2name(j), graph.adjmatrix[i][j] + pop.accum_weight));
                // if it is in the priority queue
                else 
                    updateQ(s, graph.adjmatrix[i][j] + pop.accum_weight);

                printHeap(q);
            }
        }
    }
    for (i = 0; i < graph.vertexCnt; i++)
    {
        printf("%d ", accum_cost[i]);
    }
    puts("");
    return accum_cost[name2int(endVertex)];
}

int main(int argc, char const *argv[])
{
    if (argc < 2)   fp = stdin;
    else 
    {
        fp = fopen(argv[1], "rt");
        if (fp == NULL)
            exit(1);
    }

    initGraph(fp);
    struct pq * hp = initHeap();
    printHeap(hp);

    printGraph();

    char start = 'a';
    char end = 'k';
    int cost = PFS(start, end, hp);
    printf("Route %c -- %c\nFinal Cost: %d\n", start, end, cost);

    terminHeap(hp);
    fclose(fp);
    return 0;
}