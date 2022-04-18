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

void TailPush(Sql**plist, TYPE x);//尾插
void PrintNote( Sql* plist);//打印
void FirstNote(Sql**plist,TYPE x);//创建节点
void HeadPush(Sql** plist, TYPE x);//头插
void DelHead(Sql**plist);//头删
void DelTail(Sql**plist);//尾删
Sql* FindNote(Sql*plist,TYPE x);//查找元素，并返回其所在节点地址
void RandomInsert(Sql**plist,TYPE x,TYPE n);//指定元素，并在该元素前插入一个节点
void RandomDel(Sql**plist,TYPE x);//删除指定元素
void Replace(Sql*plist,TYPE x,TYPE n);//替换
void Destroy(Sql**plist);//销毁单链表（释放所有内存）；