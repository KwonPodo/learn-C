/**
 * Dijkstra Algorithm
 * 
 * W[x,y] = if (x == y) 0
 *          else if (x is not adjacent to y) infinity or a very big number
 *          else (x is adjacent to y) weight
 * 
 * Let distance of start vertex from start vertex = 0
 * Let distance of all other vertices from start = Infinity
 * 
 * While vertices remain unvisited => Unvisited vertices are in HEAP
 *      Visit unvisited vertex with smallest known distance from start vertex(call this current vertex)
 *      FOR each unvisited neighbour of the current vertex
 *          Calculate the distance from start vertex
 *          If the calculated distance of this vertex is less than the known distance
 *              Update shortest distance to this vertex
 *              Update the previous vertex with the current vertex
 *          END If
 *  
 *      NEXT unvisited neighbour
 *      Add the current vertex to the list of visited vertices
 *      END WHILE
 * 
 * 1. For the current vertex, examine its unvisited neighbor
 * 2. Calculate the distance of each neighbor from the start vertex
 * 3. If the calculated distance of a vertex is less than the known distance, update the shortest distance
 * 4. Update the previous vertex for each of the updated distances;
 * 5. Add the current vertex to the list of the visited vertices
 * 6. Algorithm begins to repeat
 *      Visit the unvisited vertex with the smallest known distance from the start vertex.
 *      1 - 5 repeats again.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define VMAX 9
#define EMAX 12

int graph[VMAX][VMAX];
int distance[VMAX];
bool check[VMAX];
int checked = 0;
int parent[VMAX];

struct node
{
    char vertex;
    int route_weight;
};

struct tagQueue
{
    struct node heap[VMAX+1];
    int heapCnt;
}queue;

char int2name(int name)
{
    return name + 'a';
}

int name2int(char name)
{
    return name - 'a';
}

struct node createNode(char vertex, int weight)
{
    struct node new = {.vertex = vertex, .route_weight = weight};

    return new;
}

void initQ()
{
    queue.heapCnt = 0;
    int i = 0;
    for (i = 0; i < VMAX+1; i++)
    {
        queue.heap[i].route_weight = 0;
        queue.heap[i].vertex = 'R';
    }
}

void enque(struct node new)
{
    if (queue.heapCnt >= VMAX)
    {
        printf("Queue is Full!\n");
        return;
    }

    queue.heap[++queue.heapCnt] = new;

    int parent = queue.heapCnt / 2;
    int child = queue.heapCnt;

    while (parent > 0 && queue.heap[parent].route_weight > queue.heap[child].route_weight)
    {
        // swap
        struct node temp = queue.heap[parent];
        queue.heap[parent] = queue.heap[child];
        queue.heap[child] = temp;

        child = parent;
        parent = child / 2;
    }
}

struct node deque()
{
    struct node dq = queue.heap[1];
    queue.heap[1] = queue.heap[queue.heapCnt--];

    int i = 1;
    while (i <= queue.heapCnt/2)
    {
        int prior_idx = (queue.heap[i<<1].route_weight < queue.heap[(i<<1) + 1].route_weight) ? i<<1 : (i<<1)+1;
        if (queue.heap[prior_idx].route_weight < queue.heap[i].route_weight)
        {
            // swap
            struct node temp;
            temp = queue.heap[prior_idx];
            queue.heap[prior_idx] = queue.heap[i];
            queue.heap[i] = temp;

            i = prior_idx;
        }
        else
            break;
    }

    return dq;
}

void printQ()
{
    int i;
    for (i = 1; i <= queue.heapCnt; i++)
        printf("Vertex: %c\tRoute Weight: %d\n", queue.heap[i].vertex, queue.heap[i].route_weight);

    puts("");
}

void initGraph()
{
    int i, j;
    for (i = 0; i < VMAX; i++)
    {
        for (j = 0; j < VMAX; j++)
        {
            graph[i][j] = 1000;
            if (i == j)
                graph[i][j] = 0;
        }
    }

    graph[0][1] = graph[1][0] = 35;
    graph[0][4] = graph[4][0] = 247;
    graph[1][5] = graph[5][1] = 150;
    graph[1][2] = graph[2][1] = 126;
    graph[2][3] = graph[3][2] = 117;
    graph[2][5] = graph[5][2] = 162;
    graph[2][6] = graph[6][2] = 220;
    graph[4][5] = graph[5][4] = 82;
    graph[5][6] = graph[6][5] = 154;
    graph[4][7] = graph[7][4] = 98;
    graph[5][7] = graph[7][5] = 120;
    graph[6][8] = graph[8][6] = 106;
}

void printGraph()
{
    int i, j;

    for (i = 0; i < VMAX; i++)
    {
        printf("graph[%d]: ", i);
        for (j = 0; j < VMAX; j++)
            printf("%4d  ", graph[i][j]);
        puts("");
    }
    puts("");
}

void dijkstra_Search(char start)
{
    int i, j;
    int s = name2int(start);

    // init distance[]
    for (i = 0; i < VMAX; i++)
        distance[i] = 1000;
    distance[s] = 0;

    // init parent[]
    for (i = 0; i < VMAX; i++)
        parent[i] = s;
    parent[s] = -1;
    
    enque(createNode(start, 0));

    while (queue.heapCnt > 0)
    {
        struct node pop = deque();
        s = name2int(pop.vertex);
        check[s] = true;

        for (i = 0; i < VMAX; i++)
        {
            if (s != i && graph[s][i] && !check[i])
            {
                if (distance[i] > distance[s] + graph[s][i])
                {
                    distance[i] = distance[s] + graph[s][i];
                    parent[i] = s;
                    enque(createNode(int2name(i), graph[s][i]));
                }
            }
        }
    }
}

void printParent()
{
    int i;
    printf("Parent: ");
    for (i = 0; i < VMAX; i++)
        printf("%d ", parent[i]);
    
    puts("");
}

void printDistance()
{
    int i;
    printf("Distance: ");
    for (i = 0; i < VMAX; i++)
    {
        printf("%d ", distance[i]);
    }
    puts("");
}

void printRoute(char src, char dest)
{
    int d = name2int(dest);
    int t = d;
    int route_reverse[VMAX];
    int cnt = 0;

    printf("Route %c to %c : ", src, dest);

    while (t != -1)
    {
        route_reverse[cnt++] = t;
        t = parent[t];
    }

    int i;
    for (i = cnt-1; i >= 0; i--)
    {
        printf("%c", int2name(route_reverse[i]));
        if (i != 0)
            printf("-> ");
        else    
            printf("\n");
    }

    printf("Cost: %d\n", distance[d]);
}

int main(int argc, char const *argv[])
{
    initQ();
    initGraph();
    printGraph();
    dijkstra_Search('b');
    printDistance();
    printParent();
    printRoute('b', 'e');

    return 0;
}
