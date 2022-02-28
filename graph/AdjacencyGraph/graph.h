#ifndef GRAPH_H
#define GRAPH_H

struct edge {
    int weight;
    struct vertex *adjVertex;
    struct edge *nextEdge;
};

struct vertex {
    int name;
    struct vertex *next;
    // 인접한 정점들의 목록
    struct edge *adjacencyList;
};

struct graph {
    int vertexCount;
    struct vertex *vertices;
};

void initGraph(struct graph *g);
void terminateGraph(struct graph *g);

struct vertex* searchVertex(const struct graph *g, int name);

struct vertex *createVertex(int name);
void destroyVertex(struct vertex *v);

struct edge *createEdge(struct vertex *toVertex, int weight);
void destroyEdge(struct edge *);

void addVertex(struct graph *g, struct vertex *v);
int removeVertex(struct graph *g, struct vertex *v);

void addEdge(struct vertex *fromVertex, struct edge *e);
void removeEdge(struct vertex *fromVertex, struct vertex *toVertex);

void printAdj(const struct vertex *);
void printGraph(const struct graph *);

#endif