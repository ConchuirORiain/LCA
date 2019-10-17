#include <stdio.h>
#include <stdlib.h>

struct queue{
    struct queueNode *head;
};

struct queueNode{
    int data;
    struct queueNode *next;
};

struct queue *newEmptyQueue(){
    struct queue *result = malloc(sizeof(struct queue));
    result -> head = NULL;
    return result;
}

struct queueNode *newQueueNode(int x){
    struct queueNode *result = malloc(sizeof(struct queueNode));
    result->next = NULL;
    result->data = x;
    return result;
}

int enqueue(struct queue *queue, int x){
    struct queueNode *node = newQueueNode(x);
    if(queue->head == NULL){
        queue->head = node;
        return 1;
    }
    else{
        node->next = queue->head;
        queue->head = node;
        return 1;
    }
    return 0;
}

struct queueNode *dequeue(struct queue *queue){
    if(queue->head == NULL)
        return NULL;
    else if(queue->head->next == NULL){
        struct queueNode *node = queue->head;
        queue->head = NULL;
        return node;
    }
    else{
        struct queueNode *currentNode = queue->head->next;
        struct queueNode *prevNode = queue->head->next;
        while(currentNode->next != NULL){
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = NULL;
        return currentNode;
    }
} 

int isEmpty(struct queue *queue){
    if(queue->head == NULL)
        return 1;
    return 0;
}
