#include <stdio.h>
#include <stdlib.h>

struct queue{
    struct queueNode *head;
}

struct queueNode{
    int data;
    struct queueNode->next;
}

struct queue *newEmptyQueue().
struct queueNode *newQueueNode(int x);
int enqueue(struct queue *queue, int x);
struct queueNode *dequeue(struct queue *queue, int x) ;
