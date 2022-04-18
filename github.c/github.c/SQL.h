#define pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef int TYPE;
typedef struct Sql
{
	TYPE date;
	struct Sql* note;

}Sql;

void TailPush(Sql**plist, TYPE x);//β��
void PrintNote( Sql* plist);//��ӡ
void FirstNote(Sql**plist,TYPE x);//�����ڵ�
void HeadPush(Sql** plist, TYPE x);//ͷ��
void DelHead(Sql**plist);//ͷɾ
void DelTail(Sql**plist);//βɾ
Sql* FindNote(Sql*plist,TYPE x);//����Ԫ�أ������������ڽڵ��ַ
void RandomInsert(Sql**plist,TYPE x,TYPE n);//ָ��Ԫ�أ����ڸ�Ԫ��ǰ����һ���ڵ�
void RandomDel(Sql**plist,TYPE x);//ɾ��ָ��Ԫ��
void Replace(Sql*plist,TYPE x,TYPE n);//�滻
void Destroy(Sql**plist);//���ٵ������ͷ������ڴ棩��