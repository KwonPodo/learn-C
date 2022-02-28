#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"
#include "priorityQ.h"

FILE *fp;

/**
 * Kruscal Algorithm
 * 
 * 최소비용신장트리를 특정한 지점에서 부터 최소비용의 가중치를 지닌 간서을 하나하나 이어붙이는 우선순위탐색과는 다르게,
 * Kruskal 알고리즘은 최소비용신장트리의 간선들을 여기저기서 찾아내는 방법을 보인다.
 *      그러니까, 전체 그림에서 최소의 가중치를 지닌 간선을 찾아 가중치의 비용 순서대로 최소비용신장트리에 붙이는 방식이다.
 * 
 * 1. 남아있는 간선들 중, 가중치가 가장 작은 간선들을 찾은 뒤, 최소비용신장트리에 구성한다.
 *      (중요) : 단, 이때 회로(Cycle)가 생기지 않도록 트리를 구성한다.
 * 
 * 2. 모든 정점들을 이은 신장트리가 구성될 때까지 1을 반복한다.
 *          -> graph변수에 있는 bool check 배열로 모든 정점이 이어졌는지 확인
 * 
 * 문제점
 *  1. 가중치가 가장 작은 간선들을 어떻게 찾는가
 *          -> 간선들로 이루어진 우선순위 큐를 구성하고, 우선순위의 기준은 간선의 가중치로 설정한다.
 *          우선순위큐를 정렬한다. => 이럴거면 그냥 배열로 동적할당하여 구성한 뒤 정렬하는게 낫지 않나?
 *          => 애초에 회로를 만들어지지 않는 이들로 우선순위 큐를 채운다. 
 * 
 *  2. 어떠한 간선을 선택했을 때 회로의 생성여부를 어떻게 판단하는가
 *          -> 선택한 간선의 두 정점이 서로 연결되어 있는가?를 판단해본다.
 *              if 연결되어 있다면 => 해당 간선을 트리에 추가하게 된다면 회로가 생성된다.
 *              else 연결되어 있지 않다면 => 해당 간선을 트리에 추가해도 회로가 생성되지 않는다.
 *                      따라서 연결되어 있지 않을 때 해당 간선을 최소비용신장트리의 일부로 추가한다.
 * 
 *              연결되어 있다의 의미 = 두 정점이 이어지는 경로가 존재하는가?
 *              => 두 정점이 이어지는 경로의 존재유무를 어떻게 파악하나?
 *                 분리집합을 이용. 만약 두 정점이 같은 집합에 속해 있다면, 동일한 연결요소에 속해있다는 뜻이 되므로
 *                  if 같은 집합에 속해 있다면 => 트리에 추가하지 않는다.
 *                  else 같은 집합에 속해 있지 않다면 => 해당 간선을 트리에 추가한다.
 * 
 *  3. 모든 정점을 방문했는지 유무를 어떻게 파악하는가
 *          3.1 구성된 최소비용신장트리의 간선의 수가 V-1이면 구성이 완료된 것.
 *          3.2 혹은 graph.check 배열의 모든 요소가 참이면 모든 정점을 방문한 것이다.
 */

int isConnected(int set[], int v1, int v2)
{
    int i, j;
    i = v1, j = v2;

    while (set[i] >= 0)
    {
        i = set[i];
    }
    
    while (set[j] >= 0)
    {
        j = set[j];
    }

    return i == j;
}

int kruskal()
{
    int i, j;
    int v1, v2;
    int cost = 0;
    int mcst_edgeCnt = 0;
    int mcsTree[graph.vertexCnt];

    // 분리집합 초기화, 각각의 정점들을 개별적인 집합으로 구성 => vertexCnt만큼의 집합 배열로 구현
    memset(mcsTree, -1, sizeof(mcsTree));

    // 우선순위 큐 생성
    for (i = 0; i < graph.vertexCnt; i++)
        for (j = i + 1; j < graph.vertexCnt; j++)
            if (graph.adjmatrix[i][j])
                enque(createNode(int2name(i), int2name(j), graph.adjmatrix[i][j]));

    printQ();

    while (!isEmpty())
    {
        struct node *pop = deque();
        v1 = name2int(pop->e.v1); v2 = name2int(pop->e.v2);

        // 만약 꺼낸 간선이 회로를 구성하지 않는다면
        // == 만약 두 정점이 이어져 있지 않다면 
        // == 같은 집합에 속해 있지 않다면
        // 두 집합을 결합시킨다. => 같은 집합으로 합쳐서 연결시킨다.
        // => 분리집합의 최종본이 바로 최소비용신장트리가 된다.
        if (!isConnected(mcsTree, v1, v2))
        {
            printf("Add\nv1:%c\tv2:%c\tweight:%d\n\n", pop->e.v1, pop->e.v2, pop->e.weight);
            mcst_edgeCnt++;
            cost += pop->e.weight;

            // 분리집합의 결합 = 한 집합의 루트가 다른 집합의 루트의 자식이 됨
            i = v1; j = v2;
            while (mcsTree[i] >= 0)
                i = mcsTree[i];
            
            while (mcsTree[j] >= 0)
                j = mcsTree[j];
            
            mcsTree[i] = j;
        }

        if (mcst_edgeCnt == graph.vertexCnt - 1) 
            break;
    }

    return cost;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)   
        fp = stdin;
    else 
    {
        fp = fopen(argv[1], "rt");
        if (fp == NULL)
            exit(1);
    }

    initQ();
    initGraph(fp);
    printGraph();

    int cost = kruskal();

    printf("Minimum Cost : %d\n", cost);

    terminateQ();
    fclose(fp);
    return 0;
}