#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initGraph(struct graph *g) {
    g->vertexCount = 0;
    g->vertices = NULL;
}

void terminateGraph(struct graph *g) {
    if (g->vertices == NULL) g->vertexCount = 0;
    else {
        struct vertex *v = g->vertices;

        while (v != NULL) {
            struct edge *e = v->adjacencyList;
            struct edge *prev_e = e;

            if (e == NULL) v = v->next;
            else {
                do {
                    e = e->nextEdge;
                    free(prev_e);
                    prev_e = e;
                } while (prev_e != NULL);
            }
        }

        g->vertexCount = 0;
    }
}

struct vertex* searchVertex(const struct graph *g, int name) {
    if (g->vertexCount == 0) return NULL;
    else {
        struct vertex *v = g->vertices;

        while (v != NULL) {
            if (v->name == name) return v;
            v = v->next;
        }

        return NULL;
    }
}

struct vertex* createVertex(int name) {
    struct vertex *v = (struct vertex*)malloc(sizeof(struct vertex));
    if (v == NULL) return NULL;

    v->name = name;
    v->adjacencyList = NULL;
    v->next = NULL;

    return v;
}


void addVertex(struct graph *g, struct vertex *v) {
    if (g->vertices == NULL) g->vertices = v;
    else {
        struct vertex *s = g->vertices;
        while (s->next != NULL) {
            s = s->next;
        }

        s->next = v;
    }

    g->vertexCount++;
}

// v와 연결된 다른 vertex들의 adjList를 뒤져서 삭제
int removeVertex(struct graph *g, struct vertex *v) {
    struct vertex *prev_v;
    if (g->vertexCount == 0) return 0;
    else {
        if (v->adjacencyList != NULL) {
            do {
                removeEdge(v->adjacencyList->adjVertex, v);
                removeEdge(v, v->adjacencyList->adjVertex);
            } while (v->adjacencyList != NULL);
        }
    }

    if (g->vertices == v) {
        g->vertices = v->next;
    } else {
        prev_v = g->vertices;
        while (prev_v->next != v) {
            prev_v = prev_v->next;
        }
        prev_v->next = v->next;
    }

    free(v);

    g->vertexCount--;
    return 1;
}

struct edge* createEdge(struct vertex *toVertex, int weight) {
    struct edge *e = (struct edge*)malloc(sizeof(struct edge));
    if (e == NULL) return NULL;

    e->weight = weight;
    e->adjVertex = toVertex;
    e->nextEdge = NULL;

    return e;
} 

void destroyEdge(struct edge *e) {
    free(e);
}

void addEdge(struct vertex *fromVertex, struct edge *e) {
    struct edge *s = fromVertex->adjacencyList;
    if (s == NULL) fromVertex->adjacencyList = e;
    else {
        while (s->nextEdge != NULL) {
            s = s->nextEdge;
        }

        s->nextEdge = e;
    }
}

void removeEdge(struct vertex *fromVertex, struct vertex *toVertex) {
    struct edge *s = fromVertex->adjacencyList;
    struct edge *prev_s = fromVertex->adjacencyList;

    if (s->adjVertex == toVertex) {
        fromVertex->adjacencyList = NULL;
    } else {
        while (s->adjVertex != toVertex) {
            prev_s = s;
            s = s->nextEdge;
        }
        prev_s->nextEdge = s->nextEdge;
    }

    destroyEdge(s);
}

void printAdj(const struct vertex *v) {
    if (v->adjacencyList == NULL) puts("There are no Adjacent Vertices in the graph");
    else {
        printf("%d : ", v->name);
        struct edge *s = v->adjacencyList;
        while (s != NULL) {
            printf("-> %d ", s->adjVertex->name);
            s = s->nextEdge;
        }

        puts("");
    }
}

void printGraph(const struct graph *g) {
    // int i;

    if (g->vertexCount == 0) puts("There are no Vertices in the graph");
    else {
        printf("Vertex Count : %d\n", g->vertexCount);
        struct vertex *v = g->vertices;
        while (v != NULL) {
            printf("%d  ", v->name);

            struct edge *e = v->adjacencyList;
            if (e != NULL) {
                do {
                    printf("-> %d", e->adjVertex->name);
                    e = e->nextEdge;
                } while (e != NULL);
            }
            
            v = v->next;
            puts("");
        }
    }

    puts("");
}