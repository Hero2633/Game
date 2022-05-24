#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct BingNote
{

	struct BingNote* left;
	char val;
	struct BingNote* right;
}BT;
typedef struct BingNote* QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	int count;
	QNode* head;
	QNode* tail;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int Queue_Size(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);
