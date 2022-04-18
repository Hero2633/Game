#define _CRT_SECURE_NO_WARNINGS
#include"SQL.h"
void TailPush(Sql** plist, TYPE x)//β��
{
	if (*plist == NULL)//û��ͷ�ڵ�Ļ��ʹ�һ��,���ѵ�һ�����ݷŽ�����ڵ㣬��ʱ����Ͳ����������ˣ�����x��ֵ����2��
	{
		FirstNote(plist, x);
		return;
	}
	Sql* ptmp = *plist;//ͷ�ڵ�ĵ�ַ
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
void PrintNote( Sql*plist)//��ӡÿ���ڵ�
{
	Sql* tmp = plist;
	while (tmp)
	{
		printf("%d->",tmp->date);
		tmp = tmp->note;
	}
	printf("NULL\n");
}

void FirstNote(Sql** plist,TYPE x)//ͷ�ڵ�Ĵ���,���Ұѵ�һ�ε����ݷŽ���
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
	*plist = NewNote;//�Ѵ�ʱ�¿��ٵĽڵ�ĵ�ַ��Ϊ�µ�phead��*plist�ȼ���phead��

}
void DelHead(Sql** plist)//ͷɾ��ɾ��һ������ǵðѣ���ɾ���Ľڵ㣩�Ŀռ��ͷ���
{
	assert(*plist);
	Sql*ptmp=*plist;
	*plist =  ptmp->note;
	free(ptmp);
	ptmp = NULL;
	
}
void DelTail(Sql** plist)//βɾ
{
	int k = 0;
	assert(*plist);
	Sql* ptmp = *plist;
	Sql* tmp = ptmp;
	while (ptmp->note != NULL)
	{
		k++;
		 tmp = ptmp;//��¼��һ���ڵ㣨β�ڵ����һ���ڵ㣩
		ptmp = ptmp->note;
	}
	//�жϵ�һ���ڵ��ǲ���β�ڵ�
	if (k != 0)//����β�ڵ�
	{
		free(tmp->note);
		tmp->note = NULL;
	}
	else//��β�ڵ�
	{
		free(*plist);
		*plist = NULL;
	}
}
Sql* FindNote(Sql* plist,TYPE x)//����xԪ������Ԫ�����ڽڵ�λ��
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
void RandomInsert(Sql** plist,TYPE x,TYPE n)//�������
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

void RandomDel(Sql** plist,TYPE x)//���ɾ��
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