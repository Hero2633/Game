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
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	int count;
	QNode* head;
	QNode* tail;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int Queue_Size(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
