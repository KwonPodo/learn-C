#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "priorityQ.h"



// dummy head, dummy tail
void initQ()
{
    pq.head = (struct node*)malloc(sizeof(struct node));
    pq.tail = (struct node*)malloc(sizeof(struct node));

    pq.head->e.weight = INT_MIN;
    pq.head->next = pq.tail;
    pq.head->prev = pq.head;

    pq.tail->e.weight = INT_MAX;
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

struct node* createNode(char v1, char v2, int weight)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->e.v1 = v1;
    new->e.v2 = v2;
    new->e.weight = weight;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void enque(struct node *n)
{
    struct node *s = pq.head->next;

    while (s != pq.tail)
    {
        if (s->e.weight > n->e.weight) break;
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
        printf("vertex1: %c\tvertex2: %c\tweight: %d\n\n", s->e.v1, s->e.v2, s->e.weight);
        s = s->next;
    }
}

void updateQ(char vertex, int updateWeight)
{
    struct node *s = pq.head->next;

    while (s != pq.tail)
    {
        // if (s->vertex == vertex)
        // {
        //     if (s->weight > updateWeight)
        //         s->weight = updateWeight;
        //     break;
        // }

        s = s->next;
    }
}