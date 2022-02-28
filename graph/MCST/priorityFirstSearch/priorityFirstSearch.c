#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 30

FILE *fp;

// Priority Queue Configuration
struct node 
{
    char vertex;
    int weight;
    struct node *next;
    struct node *prev;
};

struct priorityQueue
{
    struct node *head;
    struct node *tail;
}pq;

int name2int(char ch)
{
    return ch - 'a';
}

char int2name(int i)
{
    return i + 'a';
}

// dummy head, dummy tail
void initQ()
{
    pq.head = (struct node*)malloc(sizeof(struct node));
    pq.tail = (struct node*)malloc(sizeof(struct node));

    pq.head->weight = INT_MIN;
    pq.head->next = pq.tail;
    pq.head->prev = pq.head;

    pq.tail->weight = INT_MAX;
    pq.tail->next = pq.tail;
    pq.tail->prev = pq.head;
}

void terminateQ()
{
    struct node *s = pq.head->next;
    struct node *n = s->next;

    while (s != pq.tail)
    {
        free(s);
        s = n;
        n = n->next;
    }
}

int isEmpty()
{
    return pq.head->next == pq.tail;
}

struct node* createNode(char vertex, int weight)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->vertex = vertex;
    new->weight = weight;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void enque(struct node *n)
{
    struct node *s = pq.head->next;

    while (s != pq.tail)
    {
        if (s->weight > n->weight) break;
        else
            s = s->next;
    }

    n->prev = s->prev;
    n->next = s;

    n->prev->next = n;
    n->next->prev = n;
}

struct node* deque()
{
    struct node *r = pq.head->next;
    pq.head->next = pq.head->next->next;
    pq.head->next->prev = pq.head;

    r->prev = r->next = NULL;

    return r;
}

void printQ()
{
    struct node *s = pq.head->next;

    while (s != pq.tail)
    {
        printf("vertex: %c\tweight: %d\n\n", s->vertex, s->weight);
        s = s->next;
    }
}

void updateQ(char vertex, int updateWeight)
{
    struct node *s = pq.head->next;

    while (s != pq.tail)
    {
        if (s->vertex == vertex)
        {
            if (s->weight > updateWeight)
                s->weight = updateWeight;
            break;
        }

        s = s->next;
    }
}

// Weight Graph Configuration - Adjacent Matrix
struct tagGraph
{
    int vertexCnt;
    int edgeCnt;
    int adjmatrix[MAX][MAX];

    int check[MAX];
}graph;


void initCheck()
{
    memset(graph.check, 0, sizeof(graph.check));
}

void initGraph()
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

    printf("Enter two vertices that consists an edge\n");
    fscanf(fp, " %c %c", &c1, &c2);
    printf("c1: %c, c2: %c\n\n", c1, c2);

    printf("Enter weight of the given edge\n");
    fscanf(fp, "%d", &weight);
    printf("weight: %d\n\n", weight);

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
        graph.adjmatrix[i][i] = 1;
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


// Priority First Search
int PFS(char ch)
{
    int i, j, result = 0;
    int min_weight, min_vertex;
    char name;
    
    initCheck();

    struct node *first = createNode(ch, 0);
    enque(first);
    graph.check[name2int(first->vertex)] = 1;

    while (!isEmpty())
    {
        struct node *pop = deque();

        i = name2int(pop->vertex);
        printf("weight: %d\n", pop->weight);
        result += pop->weight;
        
        for (j = 0; j < graph.vertexCnt; j++)
        {
            if (i == j) continue;

            // 모든 정점들을 살펴서 i와 직접적으로 인접한 주변 노드일 경우
            if (graph.adjmatrix[i][j])
            {
                // 해당 정점 j가 우선순위 큐에 들어있다면
                if (graph.check[j])
                {
                    // 우선순위 큐에 들어있는 정점 j가 현재 i의 주변 노드일때
                    // 더 작은 가중치로 가중치를 갱신한다.
                    name = int2name(j);
                    updateQ(name, graph.adjmatrix[i][j]);
                }
                // 우선순위 큐에 아직 넣지 않았다면 
                else 
                {
                    // 노드를 만들어 현재 i와의 간선 가중치를 적용하여 인큐, 체크
                    struct node *new = createNode(int2name(j), graph.adjmatrix[i][j]);
                    enque(new);
                    graph.check[j] = 1;
                }
            }
        }
    }

    printf("minimum cost of spanning tree which starts with a: %d\n", result);
    return result;
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

    initQ();
    initGraph();
    printGraph();
    PFS('a');

    terminateQ();
    fclose(fp);
    return 0;
}
