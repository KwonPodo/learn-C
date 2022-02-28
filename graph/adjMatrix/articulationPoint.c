#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

struct tagGraph
{
    int vertexCount;
    int edgeCount;
    int matrix[MAX][MAX];
}graph;

int check[MAX];

int name2int(char ch)
{
    return ch - 'a';
}

char int2name(int i)
{
    return i + 'a';
}

void initGraph(int vcnt, int ecnt)
{
    int i;
    int vertex[2] = {0};
    char v1, v2;

    graph.edgeCount = ecnt;
    graph.vertexCount = vcnt;

    for (i = 0; i < ecnt; i++)
    {
        printf("Enter two vertices that consists an edge : ");
        scanf(" %c %c", &v1, &v2);

        vertex[0] = name2int(v1);
        vertex[1] = name2int(v2);

        graph.matrix[vertex[0]][vertex[1]] = 1;
        graph.matrix[vertex[1]][vertex[0]] = 1;
    }
}

void initCheck()
{
    memset(check, 0, MAX);
}

void printMatrix()
{
    int i, j;

    for (i = 0; i < graph.vertexCount; i++)
    {
        printf("matrix[%d]: ", i);

        for (j = 0; j < graph.vertexCount; j++)
        {
            printf("%d ", graph.matrix[i][j]);
        }

        puts("\n");
    }
}

void DFS_recur(char ch)
{
    int i = name2int(ch);
    // printf("%c ", ch);
    check[i] = 1;

    int j;
    for (j = 0; j < graph.vertexCount; j++)
    {
        if (j == i) continue;

        if (graph.matrix[i][j] == 1)
            if (check[j] == 0)
            {
                check[j] = 1;
                char v = int2name(j);
                DFS_recur(v);
            }
    }
}

void removeEofV(char ch)
{
    int i = name2int(ch);
    int j;

    for (j = 0; j < graph.vertexCount; j++)
    {
        if (i == j) continue;

        if (graph.matrix[i][j])
        {
            graph.matrix[j][i] = 0;
            graph.matrix[i][j] = 0;
        }
    }
}

// is vertex ch an Articulation Point?
/**
 * 1. 입력받은 정점과 연결된 모든 간선을 제거한다.
 * 2. 제거한 정점을 제외한 모든 정점에서 깊이 우선 탐색을 실시하고 방문한 정점에는 방문표시를 한다.
 * 3. DFS가 한번 끝난 후에 방문기록을 확인하여 나머지 정점들중 하나라도 방문하지 못한 정점이 있다면
 *      그래프의 연결고리가 끊어져 제거한 정점을 통하지 않은 우회로가 존재하지 않다는 뜻이므로
 *      입력받은 정점은 단절점이다.
 */
int isAP(char ch)
{
    int i, j;
    int v = name2int(ch);

    // 입력받은 정점 ch와 연결된 모든 간선을 제거한다.
    removeEofV(ch);
    
    // 제거한 정점을 제외한 모든 정점부터 시작하여 DFS탐색 시작
    for (i = 0; i < graph.vertexCount; i++)
    {
        initCheck();

        // 간선을 제거한 정점에서는 탐색을 시작하지 않는다.
        if (i == v) continue;
        
        int start = int2name(i);
        DFS_recur(start);
        puts("\n");

        // DFS탐색 이후 방문기록을 확인 (제거한 정점 제외)
        for (j = 0; j < graph.vertexCount; j++)
        {
            if (j == v) continue;

            printf("check[%d]: %d\n", j, check[j]);

            // 제거한 정점을 제외하고 깊이우선탐색으로 방문기록에 없는 정점이 있다면
            // 정점 ch는 단절점이다.
            if (check[j] == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main() 
{
    int vcnt, ecnt;
    int result;
    char vertex;

    printf("Enter number of vertices : "); scanf("%d", &vcnt);
    printf("Enter number of edges : "); scanf("%d", &ecnt);

    initGraph(vcnt, ecnt);
    initCheck();

    printMatrix();
    
    printf("Enter a starting vertex : "); scanf(" %c", &vertex);

    result = isAP(vertex);

    printf("%d\n", result);
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

/**
Enter number of vertices : 7
Enter number of edges : 10
Enter two vertices that consists an edge : a b
Enter two vertices that consists an edge : a c
Enter two vertices that consists an edge : b c
Enter two vertices that consists an edge : b d
Enter two vertices that consists an edge : d e
Enter two vertices that consists an edge : d f
Enter two vertices that consists an edge : d g
Enter two vertices that consists an edge : e f
Enter two vertices that consists an edge : e g
Enter two vertices that consists an edge : f g
 */