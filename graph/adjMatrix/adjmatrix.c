#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 30

int stack[MAX_VERTICES];
int num = 0;

int push(int i)
{
    if (num >= MAX_VERTICES) return -1;
    
    stack[num++] = i;
    
    return 1;
}

int pop()
{
    if (num <= 0) return -1;

    return stack[--num];
}

struct adjMatrix {
    int vertexCount;
    int edgeCount;
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int check[MAX_VERTICES];
};

void createGraph(struct adjMatrix *g, int vcnt, int ecnt) 
{
    int i, j;

    
    for (i = 0; i < vcnt; i++)
    {
        for (j = 0; j < vcnt; j++) 
        {
            g->matrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (i = 0; i < vcnt; i++)
    {
        g->check[i] = 0;
    }
    
    g->vertexCount = vcnt;
    g->edgeCount = ecnt;
}

void printAdj(struct adjMatrix *g, int vertex, int vertexCnt) 
{
    int i;
    for (i = 0; i < vertexCnt; i++)
    {
        if (i == vertex) continue;
        if (g->matrix[vertex][i]) printf("%d ", i);
    }
    puts("");
}

// 정점의 수 v, 순회를 시작할 정점의 일련번호를 받아 i번째 정점에 연결된 연결 요소에 대해 순회한다.
// 연결되지 않은 그래프의 경우, 하나의 연결요소만 순회한다는 단점이 있다.
void DFS_recur(struct adjMatrix *g, int v, int i)
{
    int j;
    // visit()
    printf("%d ", i);
    g->check[i] = 1;

    for (j = 0; j < v; j++) 
    {
        // vertex i와 연결된 정점이 있으면
        if (g->matrix[i][j] != 0)
            // 방문한 적이 없다면
            if (g->check[j] == 0)
                DFS_recur(g, v, j);
    }
}

// 연결되지 않은 그래프도 감안하여 모든 정점을 찾는다.
// 그래프 전체 정점을 차례로 검색하면서 방문하지 않은 정점(각 연결 요소의 시작 정점)을
// 찾아서 DFS_recur함수를 호출한다.
void DFS_adjMatrix(struct adjMatrix *g, int v)
{
    int i;
    for (i = 0; i < v; i++)
    {
        g->check[i] = 0;
    }
    for (i = 0; i < v; i++)
    {
        // 전체 정점을 다 체크하면서 방문하지 않은 곳이 있다면 재귀적으로 순회를 시작한다.
        if (g->check[i] == 0) DFS_recur(g, v, i);
    }
    
}

void DFS_nr(struct adjMatrix *g) 
{
    int i, j, vertex;

    // init check
    for (i = 0; i < g->vertexCount; i++)
        g->check[i] = 0;
    
    // 초기 푸시
    for (i = g->vertexCount - 1; i > 0; i--)
    {   
        if (g->matrix[0][i] == 1) 
        {
            push(i);
            g->check[i] = 1;
        }
    }

    while (num > 0)
    {
        vertex = pop();
        printf("%d ", vertex);
        g->check[vertex] = 1;

        for (i = 0; i < g->vertexCount; i++) 
        {
            if (vertex != i && g->matrix[vertex][i] == 1)
                if (g->check[i] == 0)
                {
                    push(i);
                    g->check[i] = 1;
                }
        }
    }
}

void nrDFS_adjMatrix(struct adjMatrix *g) 
{
    int i, j;
    num = 0;
    
    // check 초기화
    for (i = 0; i < g->vertexCount; i++)
    {
        g->check[i] = 0;
    }

    for (i = 0; i < g->vertexCount; i++)
    {
        // 체크하지 않은 것이 있다면
        if (g->check[i] == 0)
        {
            // 방문할 스택 목록에 푸시하고 체크표시(어차피 방문할 거니까)
            push(i);
            g->check[i] = 1;

            while (num > 0) 
            {
                // 팝한 정점은 무조건 출력한다.
                i = pop();

                printf("%d ", i);

                for (j = 0; j < g->vertexCount; j++)
                {
                    // 현재 보고 있는 정점과 간선으로 연결된 정점이 있다면
                    if (g->matrix[i][j] != 0)
                        // 그리고 체크(방문)하지 않은 정점이라면
                        if (g->check[j] == 0)
                        {
                            // 푸시하고 체크 표시 (어차피 방문할 것이니까)
                            push(j);
                            g->check[j] = 1;
                        }
                }
            }
        }
    }
}

// Queue
int queue[MAX_VERTICES + 1];
int front, rear;

int isQEmpty()
{
    return front == rear;
}

int isQFull()
{
    return ((rear + 1) % (MAX_VERTICES + 1) == front);

}

int enque(int i)
{
    if (isQFull())
        return 0;

    queue[rear] = i;
    rear = (rear + 1) % (MAX_VERTICES + 1);

    return 1;
}

int deque()
{
    if (isQEmpty())
        return -1;

    int r = queue[front];

    front = (front + 1) % (MAX_VERTICES + 1);

    return r;
}

void nrBFS_adjMatrix(struct adjMatrix *g)
{
    int i, j;

    // init check
    for (i = 0; i < g->vertexCount; i++) 
        g->check[i] = 0;
    

    for (i = 0; i < g->vertexCount; i++)
    {
        if (g->check[i] == 0) 
        {
            enque(i);
            g->check[i] = 1;
        }

        while (!isQEmpty()) 
        {
            i = deque();
            printf("%d ", i);

            for (j = 0; j < g->vertexCount; j++)
            {
                if (g->matrix[i][j] == 1)
                    if (g->check[j] == 0)
                    {
                        enque(j);
                        g->check[j] = 1;
                    }
            }
        }
    }
}

int main()
{
    int vertexCnt, edgeCnt;
    int i, j, n;
    int from, to;
    vertexCnt = edgeCnt = 0;

    printf("Enter number of vertices: "); scanf("%d", &vertexCnt);
    printf("Enter number of edges: "); scanf("%d", &edgeCnt);

    struct adjMatrix graph;

    createGraph(&graph, vertexCnt, edgeCnt);

    for (j = 0; j < edgeCnt; j++)
    {
        printf("Enter two vertex that consists an edge: "); scanf("%d %d", &from, &to);
        graph.matrix[from][to] = 1;
        graph.matrix[to][from] = 1;
    }

    for (i = 0; i < vertexCnt; i++) 
    {
        printf("matrix[%d] : ", i);
        for (j = 0; j < vertexCnt; j++)
        {
            printf("%d ", graph.matrix[i][j]);
        }
        puts("");
    }

    // printf("Enter a vertex 0 ~ %d : ", vertexCnt);
    // scanf("%d", &n);
    // printAdj(&graph, n, vertexCnt);
    // puts("");
    // DFS_recur(&graph, vertexCnt, 0);
    puts("");
    // DFS_adjMatrix(&graph, vertexCnt);
    // DFS_nr(&graph);
    nrBFS_adjMatrix(&graph);
}


/**
Enter number of vertices: 9
Enter number of edges: 11
Enter two vertex that consists an edge: 0 1
Enter two vertex that consists an edge: 0 2
Enter two vertex that consists an edge: 0 3
Enter two vertex that consists an edge: 1 4
Enter two vertex that consists an edge: 2 5
Enter two vertex that consists an edge: 3 6
Enter two vertex that consists an edge: 4 5
Enter two vertex that consists an edge: 5 6
Enter two vertex that consists an edge: 4 7
Enter two vertex that consists an edge: 6 8
Enter two vertex that consists an edge: 7 8
 * 
 */