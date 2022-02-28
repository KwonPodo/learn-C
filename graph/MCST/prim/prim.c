/**
 * Prim's Algorithm
 * 1. 그래프와 최소신장트리를 준비한다. 이때 최소신장트리는 노드가 하나도 없는 상태
 * 2. 그래프에서 임의의 정점을 시작 정점으로 선택하여 최소신장트리의 루트 노드로 삽입한다.
 * 3. 최소신장트리에 삽입되어 있는 정점들과 이 정점들의 모든 인접 정점 사이에 있는 간선의 가중치를 조사한다.
 *      간선 중, 가장 가중치가 작은 것을 골라 이 간선에 연결되어 있는 인접 정점을 최소신장트리에 삽입한다.
 *      단, 새로 삽입되는 정점은 최소신장트리에 삽입되어 있는 기존의 노드들과 사이클을 형성해서는 안된다.
 * 4. 3의 과정을 반복하다가 최소신장트리가 그래프의 모든 정점을 연결하게 되면 알고리즘을 종료한다.
 */

#include <stdio.h>
#include "graph.h"

FILE *fp;

struct edge 
{
    char from;
    char to;
    int weight;
};

struct pq
{
    struct edge *heap;
    int heapCnt;
};

struct edge* createEdge(char v1, char v2, int weight)
{
    struct edge *new = (struct edge*)malloc(sizeof(struct edge));
    new->from = v1;
    new->to = v2;
    new->weight += weight;

    return new;
}

struct pq* initQ(struct tagGraph graph)
{
    struct pq *q = (struct pq*)malloc(sizeof(struct pq));
    q->heap = (struct edge*)malloc(graph.vertexCnt+1 * sizeof(struct edge*));
    q->heap[0].weight = 0;
    q->heap[0].from = 'R';
    q->heap[0].to = 'R';
    q->heapCnt = 0;

    return q;
}

void terminQ(struct pq *q)
{
    free(q->heap);
    free(q);
}

void printQ(struct pq * q)
{
    int i = 1;
    while (i <= q->heapCnt)
    {
        printf("%c -> %c : %d\n", q->heap[i].from, q->heap[i].to, q->heap[i].weight);
        i++;
    }
    puts("");
}

void enque(struct pq * q, struct edge *n)
{
    q->heapCnt++;
    int i = q->heapCnt;
    q->heap[i] = *n;
    while (q->heap[i/2].weight > q->heap[i].weight)
    {
        // swap
        struct edge tmp = q->heap[i];
        q->heap[i] = q->heap[i/2];
        q->heap[i/2] = tmp;
    }
}

struct edge deque(struct pq *q)
{
    struct edge root = q->heap[1];
    q->heap[1] = q->heap[q->heapCnt];
    q->heapCnt--;

    int i = 1;
    // 내부 노드에 한해서
    while (i <= q->heapCnt>>2)
    {
        int j = (q->heap[i<<2].weight < q->heap[(i<<2) + 1].weight) ? i<<2 : (i<<2) + 1;

        if (q->heap[i].weight > q->heap[j].weight)
        {
            // swap;
            struct edge tmp = q->heap[i];
            q->heap[i] = q->heap[j];
            q->heap[j] = tmp;

            i = j;
        }
        else 
            break;
    }

    return root;
}

struct edge* searchQ(struct pq *q, char v)
{
    int i;
    for (i = 1; i <= q->heapCnt; i++)
    {
        if (q->heap[i].to == v)
            return &q->heap[i];
    }

    return NULL;
}

void updateQ(struct edge *s, int cmp_weight)
{
    if (s->weight > cmp_weight)
        s->weight = cmp_weight;
}

void prim(struct tagGraph graph, struct pq *q, int mcst[][graph.vertexCnt], char start)
{
    int i, j;

    graph.check[name2int(start)] = true;
    enque(q, createEdge(start, start, 0));

    while (q->heapCnt > 0)
    {
        struct edge pop = deque(q);
        int from = name2int(pop.from);
        int to = name2int(pop.to);
        mcst[from][to] = mcst[to][from] = pop.weight;
        printf("from: %c\tto: %c\tweight: %d\n", pop.from, pop.to, pop.weight);

        for (i = 0; i < graph.vertexCnt; i++)
        {
            if (i == to) continue;

            if (graph.adjmatrix[to][i])
            {
                if (!graph.check[i])
                {
                    graph.check[i] = true;
                    enque(q, createEdge(int2name(to), int2name(i), graph.adjmatrix[to][i]));
                }
                else
                {
                    struct edge *s = searchQ(q, int2name(i));
                    updateQ(s, graph.adjmatrix[to][i]);
                }
            }
        }
    }
}

void printMCST(struct tagGraph graph, int mcst[][graph.vertexCnt])
{
    puts("");
    int i, j;

    for (i = 0; i < graph.vertexCnt; i++)
    {
        printf("mcst[%2d] : ", i);
        for (j = 0; j < graph.vertexCnt; j++)
            printf("%4d  ", mcst[i][j]);
        puts("");
    }
    puts("");
}

int main(int argc, char const *argv[])
{
    int i, j;
    if (argc < 2)   
        fp = stdin;
    else 
    {
        fp = fopen(argv[1], "rt");
        if (fp == NULL)
            exit(1);
    }

    for (i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
    }

    struct tagGraph graph;



    initGraph(fp, &graph);
    printGraph(graph);

    int mcst[graph.vertexCnt][graph.vertexCnt];
    for (i = 0; i < graph.vertexCnt; i++)
        for (j = 0; j < graph.vertexCnt; j++)
            mcst[i][j] = 0;
    
    struct pq *q = initQ(graph);

    prim(graph, q, mcst, 'b');

    printMCST(graph, mcst);

    fclose(fp);
    return 0;
}