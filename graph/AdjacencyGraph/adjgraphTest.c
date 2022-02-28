#include <stdio.h>
#include "graph.h"

enum menuList {
    Terminate,
    AddVertex,
    AddEdge,
    RemoveVertex,
    RemoveEdge,
    PrintAdj,
    PrintGraph
};

enum menuList selectMenu() {
    int select;

    do {
        puts("Enter Action (0) Terminate (1) Add Vertex (2) Add Edge (3) Remove Vertex (4) Remove Edge (5) Print Adjacent Vertices (6) Print Graph");
        printf("Action : "); scanf("%d", &select);
        puts("");
    } while (select < 0 && select > 6);

    return (enum menuList)select;
}

int main() {
    int name, v1, v2;
    struct graph adjGraph;
    struct vertex *target;
    struct vertex *vertex1, *vertex2;
    struct edge *edge1, *edge2;

    initGraph(&adjGraph);

    enum menuList menu;
    do {
        menu = selectMenu();

        switch (menu)
        {
        case Terminate:
            terminateGraph(&adjGraph);
            break;
        
        case AddVertex:
            do {
                printf("Enter Vertex Name: "); scanf("%d", &name);
                puts("");
                if (searchVertex(&adjGraph, name)) {
                    printf("Corresponding Vertex exists in the graph\n");
                    puts("Enter again\n");
                }
            } while (searchVertex(&adjGraph, name));
            target = createVertex(name);
            addVertex(&adjGraph, target);
            break;
        
        case AddEdge:
            do {
                printf("Enter two vertices that consists an edge: ");
                scanf("%d %d", &v1, &v2);
            } while (v1 == v2);

            vertex1 = searchVertex(&adjGraph, v1);
            vertex2 = searchVertex(&adjGraph, v2);

            edge1 = createEdge(vertex1, 1);
            edge2 = createEdge(vertex2, 1);

            addEdge(vertex1, edge2);
            addEdge(vertex2, edge1);
            break;
        
        case RemoveVertex:
            printf("Enter Vertex Name: "); scanf("%d", &name);
            puts("");

            target = searchVertex(&adjGraph, name);
            if (target == NULL) puts("Not Found!");
            else {
                printf("target : %d\n", target->name);
                if (!removeVertex(&adjGraph, target)) {
                    puts("No Vertex to remove");
                }
            }
            break;
        
        case RemoveEdge:
            printf("Enter two vertices that consists an edge to remove: ");
            scanf("%d %d", &v1, &v2);

            vertex1 = searchVertex(&adjGraph, v1);
            vertex2 = searchVertex(&adjGraph, v2);
            
            removeEdge(vertex1, vertex2);
            removeEdge(vertex2, vertex1);
            break;
        
        case PrintAdj:
            printf("Enter vertex name: ");
            scanf("%d", &name);
            target = searchVertex(&adjGraph, name);
            printAdj(target);
            break;
        
        case PrintGraph:
            printGraph(&adjGraph);
            break;

        default:
            break;
        }

    } while (menu != Terminate);

}