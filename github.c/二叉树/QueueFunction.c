#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
	q->count = 0;

}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	if (q->head == NULL)
	{
		QNode* newnote = (QNode*)malloc(sizeof(QNode));
		assert(newnote);
		q->head=newnote;
		q->tail = newnote;
		newnote->data = data;
		newnote->next = NULL;
	}
	else
	{
		QNode* newnote = (QNode*)malloc(sizeof(QNode));
		assert(newnote);
		newnote->data = data;
		q->tail->next = newnote;
		q->tail = newnote;
		newnote->next = NULL;
		
	}
	q->count++;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	
	assert(q->head);
	QNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (q->head == NULL)
		q->tail = NULL;
	q->count--;

}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{

	assert(q);
	assert(q->tail);
	return q->tail->data;

}
// ��ȡ��������ЧԪ�ظ��� 
int Queue_Size(Queue* q)
{
	assert(q);
	return q->count;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->count==0;

}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->head;

	while (cur!=NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;


	}



}

