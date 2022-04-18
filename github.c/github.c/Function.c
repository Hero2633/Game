#define _CRT_SECURE_NO_WARNINGS
#include"SQL.h"
void TailPush(Sql** plist, TYPE x)//尾插
{
	if (*plist == NULL)//没有头节点的话就创一个,并把第一次数据放进这个节点，此时程序就不用往下走了，以免x的值保留2次
	{
		FirstNote(plist, x);
		return;
	}
	Sql* ptmp = *plist;//头节点的地址
	assert(ptmp);
	while (ptmp->note!=NULL)
	{
		ptmp = ptmp->note;
	}
	Sql*NewNote=(Sql*)malloc(sizeof(Sql));
	assert(NewNote);
	ptmp->note = NewNote;
	NewNote->note = NULL;
	NewNote->date = x;
}
void PrintNote( Sql*plist)//打印每个节点
{
	Sql* tmp = plist;
	while (tmp)
	{
		printf("%d->",tmp->date);
		tmp = tmp->note;
	}
	printf("NULL\n");
}

void FirstNote(Sql** plist,TYPE x)//头节点的创建,并且把第一次的数据放进来
{
	Sql*p=(Sql*)malloc(sizeof(Sql));
	assert(p);
	*plist=p;
	(*plist)->note = NULL;
	(*plist)->date = x;
	
}
void HeadPush(Sql** plist,TYPE x)
{
	Sql* ptmp = *plist;
	Sql* NewNote = (Sql*)malloc(sizeof(Sql));
	assert(NewNote);
	NewNote->note = *plist;
	NewNote->date = x;
	*plist = NewNote;//把此时新开辟的节点的地址变为新的phead（*plist等价于phead）

}
void DelHead(Sql** plist)//头删，删除一个过后记得把（被删除的节点）的空间释放了
{
	assert(*plist);
	Sql*ptmp=*plist;
	*plist =  ptmp->note;
	free(ptmp);
	ptmp = NULL;
	
}
void DelTail(Sql** plist)//尾删
{
	int k = 0;
	assert(*plist);
	Sql* ptmp = *plist;
	Sql* tmp = ptmp;
	while (ptmp->note != NULL)
	{
		k++;
		 tmp = ptmp;//记录上一个节点（尾节点的上一个节点）
		ptmp = ptmp->note;
	}
	//判断第一个节点是不是尾节点
	if (k != 0)//不是尾节点
	{
		free(tmp->note);
		tmp->note = NULL;
	}
	else//是尾节点
	{
		free(*plist);
		*plist = NULL;
	}
}
Sql* FindNote(Sql* plist,TYPE x)//查找x元素所在元素所在节点位置
{
	assert(plist);
	while (plist)
	{
		if (plist->date == x)
			return plist;	
			plist = plist->note;

	}
	
		return NULL;
	

}
void RandomInsert(Sql** plist,TYPE x,TYPE n)//随机插入
{
	assert(*plist);
		Sql* FindVal = FindNote(*plist, x);
		assert(FindVal);
		Sql* tmp = *plist;
		if (*plist == FindVal)
			HeadPush(plist,n);
		else
		{
			while (tmp->note != FindVal)
			{
				if (tmp->note == FindVal)
					break;
				else
					tmp = tmp->note;
			}
			Sql* NewNote = NULL;
			FirstNote(&NewNote,n);
			tmp->note = NewNote;
			NewNote->note = FindVal;
		}
	

}

void RandomDel(Sql** plist,TYPE x)//随机删除
{
	assert(*plist);
	Sql* tmp = *plist;
	Sql* pos = FindNote(*plist,x);
	assert(pos);
	if (pos == *plist)
	{
		//*plist = pos->note;
		//free(pos);
		DelHead(plist);
		return;
	}
	while (tmp->note!=pos)
	{
		tmp = tmp->note;

	}
	tmp->note = pos->note;
	free(pos);
	
}
void Replace(Sql* plist,TYPE x,TYPE n)
{
	assert(plist);
	Sql* pos = FindNote(plist,x);
	assert(pos);
	pos->date = n;
}
void Destroy(Sql** plist)
{
	if (*plist==NULL)
	{
		return;
	}
Sql* tmp = *plist;
	while (*plist)
	{
		tmp = *plist;
		*plist = tmp->note;
		free(tmp);
	}
	
}