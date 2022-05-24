#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Queue.h"

void FrontPrint(BT*root)//ǰ�� �ڵ�->������->������
{
	if (!root)
	{
		printf(" NULL ");
		return;
	}
	printf(" %c ",root->val);
	FrontPrint(root->left);
	FrontPrint(root->right);


}
void MidPrint(BT* root)//����// ������->�ڵ�->������
{
	if (!root)
	{
		printf(" NULL ");
		return;

	}

	MidPrint(root->left);
	printf(" %c ",root->val);
	MidPrint(root->right);

}
int NoteSize(BT*root)//�ڵ����(�ݹ�˼��)
{

	if (root == NULL)
		return 0;
	else
	{
		return NoteSize(root->left) + NoteSize(root->right)+1;
	}
}
int NoteSize1(BT*root)//�����õı�����˼��Խڵ������ֻ��Ե��߳������ã����ڶ��߳���˵���������ã�
{
	static int count = 0;
	if (root == 0)
		return 0;
	++count;
	NoteSize1(root->left);
	NoteSize1(root->right);

	return count;

}
void NoteSize2(BT* root,int*count)//�����õı�����˼��Խڵ������ֻ��Ե��߳������ã����ڶ��߳���˵���������ã�
{
	
	if (root == 0)
	{
		return;
	}
	(*count)++;
	NoteSize2(root->left,count);
	NoteSize2(root->right,count);


}
void BackPrint(BT*root)//����//������->������->�ڵ�
{
	if (!root)
	{
		printf(" NULL ");
		return;
	}
	BackPrint(root->left);
	BackPrint(root->right);
	printf(" %c ",root->val);
}

int LeaveSize(BT* root)//Ҷ�ӽڵ�ĸ���(�ݹ��˼��)
{

	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return LeaveSize(root->left)+LeaveSize(root->right);
}
void WideSearch(BT*root)//�������//���������Ƚ��ȳ�
{
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	assert(tmp);
	QueueInit(tmp);
	if (root == NULL)
		return;
	QueuePush(tmp, root);
	do 
	{
		BT*front=QueueFront(tmp);
		printf(" %c ",front->val);
		BT* left = front->left;
		BT* right = front->right;
		QueuePop(tmp);
		if(left)
		QueuePush(tmp,left);
		if (right)
			QueuePush(tmp,right);
	}while (!QueueEmpty(tmp));
}


int main()
{
	BT A = { NULL,'A',NULL };
	BT B = { NULL,'B',NULL };
	BT C = { NULL,'C',NULL };
	BT D = { NULL,'D',NULL };
	BT E = { NULL,'E',NULL };
	A.left = &B;
	A.right = &C;
	B.left = &D;
	B.right = &E;
	C.left = NULL;
	C.right = NULL;
	D.right = NULL;
	D.left = NULL;
	E.right = NULL;
	E.left = NULL;
	//FrontPrint(&A);
	/*MidPrint*//*(&A);*/
	/*BackPrint(&A);*/
	/*int count=0 ;
	NoteSize2(&A,&count);
	printf("%d ", LeaveSize(&A));
	printf("%d ", NoteSize(&A));
	printf("%d ", NoteSize1(&A));
	printf("%d ",count);*/
	WideSearch(&A);
	return 0;
}