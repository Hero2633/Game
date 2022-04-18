#define _CRT_SECURE_NO_WARNINGS
#include"SQL.h"
void test1()
{
	Sql* phead = NULL;
	TailPush(&phead, 1);
	TailPush(&phead, 2);
	TailPush(&phead, 3);
	TailPush(&phead, 4);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	PrintNote(phead);
	
}
void test2() {
	Sql* phead = NULL;
	HeadPush(&phead,1);
	HeadPush(&phead,2);
	HeadPush(&phead,3);
	HeadPush(&phead,4);
	HeadPush(&phead,5);
	HeadPush(&phead,6);
	HeadPush(&phead,7);
	DelHead(&phead); 
	DelHead(&phead);
	DelHead(&phead); 
	DelHead(&phead); 
	DelTail(&phead);
	DelTail(&phead);
	DelTail(&phead);
	PrintNote(phead);

}
void test3()
{
	Sql* phead = NULL;
	HeadPush(&phead, 1);
	HeadPush(&phead, 2);
	HeadPush(&phead, 3);
	HeadPush(&phead, 4);
	HeadPush(&phead, 5);
	HeadPush(&phead, 6);
	HeadPush(&phead, 7);
	/*DelHead(&phead);
	DelHead(&phead);
	DelHead(&phead);
	DelHead(&phead);
	DelHead(&phead);
	DelHead(&phead);*/

	PrintNote(phead);
}
void test4()
{
	Sql* phead = NULL;
	TailPush(&phead, 1);
	TailPush(&phead, 2);
	TailPush(&phead, 3);
	TailPush(&phead, 4);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	TailPush(&phead, 7);
	TailPush(&phead, 9);
	TailPush(&phead, 6);

	//DelTail(&phead);
	Sql* p = FindNote(phead, 6);
	int i = 0;
	while (p)
	{if(p->date==6)
		printf("第%d个%d的地址 % p\n",++i,6,p);
		p = p->note;

	}
	/*if (FindNote(phead, 6) != NULL)
	{
		printf("找到了%d\n", FindNote(phead, 6)->date);
	}
	else
		printf("找不到\n");*/
	PrintNote(phead);

}
void test5()
{
	Sql* phead = NULL;
	TailPush(&phead, 1);
	TailPush(&phead, 2);
	TailPush(&phead, 3);
	TailPush(&phead, 4);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	/*RandomInsert(&phead, 2, 40);*/
	RandomInsert(&phead, 1, 100);
	RandomInsert(&phead, 4, 99);
	RandomInsert(&phead, 6, 60);

	PrintNote(phead);
}
void test6()
{
	Sql* phead = NULL;
	TailPush(&phead, 1);
	TailPush(&phead, 2);
	TailPush(&phead, 3);
	TailPush(&phead, 4);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	/*RandomDel(&phead,4);*/
	RandomDel(&phead, 4);
	RandomDel(&phead, 5);
	RandomDel(&phead, 1);
	RandomDel(&phead, 2);
	RandomDel(&phead, 3);
	/*RandomDel(&phead,4);*/
	PrintNote(phead);
	printf("\n");

}
test7()
{
	Sql* phead = NULL;
	TailPush(&phead, 1);
	TailPush(&phead, 2);
	TailPush(&phead, 3);
	TailPush(&phead, 4);
	TailPush(&phead, 5);
	TailPush(&phead, 6);
	/*RandomInsert(&phead,  6,  99);*/
	Replace(phead, 1, 7);
	Replace(phead,6,9);
	/*RandomDel(&phead, 1);*/
	/*RandomDel(&phead, 2);*/
	//RandomDel(&phead, 3);
	//RandomDel(&phead, 4);
	//RandomDel(&phead, 5);
	//RandomDel(&phead, 6);
	PrintNote(phead);
	Destroy(&phead);
	if (phead == NULL)
		printf("销毁成功\n");
}
int main()
{
	test1();
	/*test5();*/
	/*test6();*/
	test7();
	return 0;
} 