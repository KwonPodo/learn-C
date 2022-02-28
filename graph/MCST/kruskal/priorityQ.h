#ifndef ___PRIORITY_Q
#define ___PRIORITY_Q

struct edge
{
    char v1;
    char v2;
    int weight;
};

// Priority Queue Configuration
struct node 
{
    struct edge e;
    struct node *next;
    struct node *prev;
};

struct priorityQueue
{
    struct node *head;
    struct node *tail;
}pq;


// dummy head, dummy tail
void initQ();
void terminateQ();

int isEmpty();
struct node* createNode(char v1, char v2, int weight);

void enque(struct node *n);

struct node* deque();

void printQ();

void updateQ(char vertex, int updateWeight);

#endif