#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define SIZE 40
struct queue{
    int items[SIZE];
    int front;
    int rear;
};
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}
void enqueue(struct queue* q, int value){
    if(q->rear == SIZE-1)
        exit(0);
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
    }
    return item;
}
void printQueue(struct queue *q) {
    int i = q->front;
    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }    
}
