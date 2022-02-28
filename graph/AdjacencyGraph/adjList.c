#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// Stack
int stack[MAX_VERTEX] = {0};
int num = 0;

int push(int i)
{
    if (num >= MAX_VERTEX) return -1;

    stack[num++] = i;

    return 1;
}

int pop()
{
    if (num <= 0) return -1;

    return stack[--num];
}

// Queue
int queue[MAX_VERTEX + 1];
int front, rear;

int isQEmpty()
{
    return front == rear;
}

int isQFull()
{
    return ((rear + 1) % (MAX_VERTEX + 1) == front);

}

int enque(int i)
{
    if ((rear + 1) % (MAX_VERTEX + 1) == front)
        return -1;

    queue[rear] = i;
    rear = ++rear % (MAX_VERTEX + 1);
}

int deque(int i)
{
    if (front == rear)
        return -1;

    int r = queue[front];

    front = ++front % (MAX_VERTEX + 1);

    return r;
}

struct node {
    struct node *next;
    int vertex;
};

int check[MAX_VERTEX] = {0};

void printAll(struct node *g[], int vertexCnt)
{
    int i;
    struct node *s;
    for (i = 0; i < vertexCnt; i++)
    {
        printf("g[%d] : ", i);
        s = g[i];
        while (s != NULL)
        {
            printf("%d ", s->vertex);
            s = s->next;
        }

        puts("");
    }
}

// i 정점으로 시작하는 하나의 연결 요소를 순회하는 함수
void DFS_recur(struct node *g[], int vertexCnt, int i)
{
    int j;
    printf("%d ", i);
    check[i] = 1;

    struct node *t;
    for (t = g[i]; t != NULL; t = t->next)
    {
        // 정점과 연결된 정점들 중, 방문한 적이 없다면 재귀적으로 방문
        if (check[t->vertex] == 0)
            DFS_recur(g, vertexCnt, t->vertex);
    }
}

void DFS_adjList(struct node *g[], int vertexCnt)
{
    int i;

    // init check
    for (i = 0; i < vertexCnt; i++) check[i] = 0;

    for (i = 0; i < vertexCnt; i++)
    {
        if (check[i] == 0) 
            DFS_recur(g, vertexCnt, i);
    }
}

void DFS_nr(struct node *g[], int vertexCnt)
{
    int i,j;
    struct node *t;

    // init check
    for (i = 0; i < vertexCnt; i++)
    {
        check[i] = 0;
    }
    

    for (i = 0; i < vertexCnt; i++)
    {
        // 모든 정점들을 차례대로 보면서 
        // 방문하지 않은 정점이 있다면
        if (check[i] == 0)
        {
            // 푸시 & 방문기록 체크 => 스택에 넣는 정점은 모두 방문표시
            push(i);
            check[i] = 1;

            // 스택이 비어있지 않은 동안 계속
            while (num > 0)
            {
                // 팝하여 출력 (방문)
                i = pop();
                printf("%d ", i);

                // 해당 정점에 간선으로 연결된 정점들 중,
                for (t = g[i]; t != NULL; t = t->next)
                {
                    // 방문하지 않은 정점이 있다면
                    if (check[t->vertex] == 0)
                    {
                        // 푸시 & 방문 체크 => 스택에 넣는 정점은 모두 방문표시
                        push(t->vertex);
                        check[t->vertex] = 1;
                    }
                }
            }
        }
    }
}

void nrBFS_adjList(struct node *g[], int vertexCnt)
{
    int i, j;
    struct node *s;
    
    for (i = 0; i < vertexCnt; i++)
    {
        if (check[i] == 0)
        {
            enque(i);
            check[i] = 1;
        }

        while (!isQEmpty())
        {
            i = pop();
            printf("%d ", i);

            for (s = g[i]; s != NULL; s = s->next)
            {
                if (check[s->vertex] == 0)
                {
                    enque(s->vertex);
                    check[s->vertex] = 1;
                }
            }
        }
    }
}

int main() 
{
    int i, j;
    int vertexCnt, edgeCnt;
    int v1, v2;
    
    printf("Enter number of vertices : "); scanf("%d", &vertexCnt);
    printf("Enter number of edges : "); scanf("%d", &edgeCnt);

    struct node *graph[vertexCnt];

    for (i = 0; i < vertexCnt; i++)
    {
        graph[i] = NULL;
    }

    for (i = 0; i < edgeCnt; i++)
    {
        printf("Enter two vertices which consist an edge : ");
        scanf("%d %d", &v1, &v2);

        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->vertex = v2;
        new->next = graph[v1];
        graph[v1] = new;

        new = (struct node*)malloc(sizeof(struct node));
        new->vertex = v1;
        new->next = graph[v2];
        graph[v2] = new;
    }

    printAll(graph, vertexCnt);
    DFS_nr(graph, vertexCnt);
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