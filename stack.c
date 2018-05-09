#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50

typedef struct{
    int data[MAXSIZE];
    int top;
} SqStack;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//LiQueue
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}LiQueue;

